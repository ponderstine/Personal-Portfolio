
import random, string

# This class is for each specimen (string) in a generatiob.
class specimen:
    # Each specimen has a string and a fitness. It's fitness is defaulted at 0 until it is rated later in the algorithm.
    def __init__(self, string, fitness=0.0):
        self._string = str(string)
        self._fitness = float(fitness)

    # This is the specimen string getter.
    @property
    def string(self):
        return self._string

    # This is the specimen string setter.
    @string.setter
    def string(self, new_string):
        try:
            self._string=str(new_string)
        except:
            print('Error setting new string')

    # This is the specimen string deleter.
    @string.deleter
    def string(self):
        del self._string

    # This is the specimen fitness getter.
    @property
    def fitness(self):
        return self._fitness

    # This is the specimen fitness setter.
    @fitness.setter
    def fitness(self, new_fitness):
        try:
            self._fitness = float(new_fitness)
        except:
            print('Error setting new string')

    # This is the specimen fitness deleter.
    @fitness.deleter
    def fitness(self):
        del self._fitness


# This function takes in an input string from the user that the algorithm will try to replicate.
def goal_input(pop_size):

    # Goal string can be made of any ASCII lowercase letters, uppercase letters, digits, symbols, and whitespaces.
    letters = set(string.printable)

    # Go is True when while loop must continue. When the user has input a proper goal string then Go will be changed
    # to False
    go = True
    while go:
        goal = input('What string would you like me to replicate? :')

        # This ensures that each character in the goal string is in the acceptable list of ASCII letters and characters
        # that this algorithm uses. If all characters are in the list of approved characters then the while loop will be
        # broken and the algorithm will continue. If the goal string includes characters that are not in the ASCII
        # characters used then the user will be notified and asked to provide a different goal string.
        myChars = [char for char in goal]
        if set(myChars).issubset(letters):
            go = False
            break
        else:
            print('Invalid characters used. Please choose a string with valid characters.')
    # After string is selected, the length of the string must be determined.
    length = len(goal)

    return goal, length, letters

# This function randomly generates the generation of specimen to begin the algorithm.
def rand_pop_generator(length, pop_size, letters):
    # The code will preallocate a list of zeros for the current population. This randomly generated specimen will be
    # added to this list.
    current_pop = [0] * pop_size

    # This is a for loop to randomly generate a string for each specimen in the generation.
    for i in range(pop_size):
        rand_chars = random.sample(letters, length)
        rand_string = ''.join(rand_chars)
        current_pop[i] = specimen(rand_string)

    return current_pop

# This function calculates the "fitness" of each specimen. Fitness, in this context, is a value between 0 and 1 which is
# equal to the number of characters in the string of a specimen that match the goal string and are in the correct place
# in the string.
def rate_fitness(current_pop, pop_size, goal, length):
    # This preallocates the maximum fitness and index of the maximum fitness for later use.
    max_fitness = 0.0
    max_ind = None
    avg_fitness = 0.0

    # This for loop goes through each character in the string of each specimen and continuously adds to the fitness of
    # the string
    for j in range(pop_size):
        for k in range(length):
            if current_pop[j].string[k] == goal[k]:
                current_pop[j].fitness = float(current_pop[j].fitness + 1/length)
        # if the fitness of the previous specimen is greater than the maximum fitness of all the previous specimen, then
        # the maximum fitness and index of the specimen with maximum fitness is recorded.
        if current_pop[j].fitness > max_fitness:
            max_fitness = current_pop[j].fitness
            max_ind = j
        # This iterates and adds up the average fitness of the entire generation.
        avg_fitness += current_pop[j].fitness / pop_size

    return current_pop, max_fitness, max_ind, avg_fitness

# This function prints the data to the command window.
def save_print_data(current_pop, gen_num, max_fitness, max_ind, avg_fitness):

    max_percent = max_fitness * 100
    avg_percent = avg_fitness * 100
    print(f'Gen. {gen_num}: Best string is {current_pop[max_ind].string}, the avg. fitness is {avg_percent:.1f}%, and the max fitness is {max_percent:.1f}% ')


# This function builds the mating pool that will be used to breed the next generation.
def build_mating_pool(current_pop, pop_size, max_fitness):
    # This sets the ticket factor to determine how many tickets a specimen gets in the breeding pool for every character
    # it has that matches the goal string rounded to the nearest ticket.
    ticket_factor = 10
    # This preallocates a list of zeros for the normalized fitness.
    normalized_fitness = [0] * pop_size

    # if the maximum fitness of the generation is zero, there is no reason to normalize the fitness since all of the
    # strings have the same fitness. if the maximum fitness of the generation is not zero, then the fitness is
    # normalized to so that specimen with fitness closer to the maximum fitness get even more tickets in the breeding
    # pool.
    if max_fitness == 0:
        for i in range(0,pop_size):
            normalized_fitness[i] = current_pop[i].fitness
    else:
        for i in range(0,pop_size):
            normalized_fitness[i] = (current_pop[i].fitness/max_fitness) ** 3

    # This preallocates the mating pool.
    mating_pool=[]

    # For every specimen in the generation, they get 1 ticket automatically and a proportional amount of tickets for
    # their normalized fitness and the predetermined ticket factor.
    for i in range(0, pop_size):
        num_tickets = 1 + round(ticket_factor * normalized_fitness[i])
        # For every specimen, this creates a list with the number of elements equivalent to the number of tickets a
        # specimen gets. Every element is the index to the specimen in the current generation. The lists are then
        # concatenated to get the mating pool. The mating pool is a list (like a ticket raffle) that has the number
        # index for each epecimen in the generation. Each index counts as a ticket for that specimen in the mating pool.
        myList = [0] * num_tickets
        for j in range(0,len(myList)):
            myList[j]=i
        mating_pool=mating_pool+myList

    return mating_pool

# This function breeds the new generation of specimen from the mating pool (ticket raffle)
def mating(mating_pool, current_pop, pop_size, length):
    # This preallocates the new generation of specimen with a list of zeros.
    new_pop = [0] * pop_size
    # For every member of the new population, a new string is created.
    for i in range(0, pop_size):
        # A new string is preallocated with zeros to be filled in with characters later.
        myString = [0] * length
        # This checks to make sure that a string does not have the same parent twice to help with genetic diversity.
        # If the second parent is the same index as the first parent then the second parent is reselected until there
        # are two unique indexes to specimen for parents.
        while True:
            parent1_ind = random.choice(mating_pool)
            parent2_ind = random.choice(mating_pool)
            if parent1_ind != parent2_ind:
                break

        # This gets the specimen strings for the 2 parents
        parent1=current_pop[parent1_ind].string
        parent2=current_pop[parent2_ind].string

        # This randomly selects which parent, 1 or 2, that will provide the character for each character in the string
        # for the new specimen.
        for j in range(0,length):
            if random.randint(1,2)==1:
                myString[j] = parent1[j]
            else:
                myString[j] = parent2[j]

        # This joins the characters of the new specimen into a string and creates a new specimen in the new generation
        # with the string.
        new_string=''.join(myString)
        new_pop[i]=specimen(new_string)

    return new_pop

# This function randomly adds mutation to the breeding process at a determined rate.
def mutation(new_pop, pop_size, length, mutation_rate, letters):

    # For every specimen in the new population, a new characters list is preallocated with zeros.
    for i in range(0, pop_size):
        myChars = [0] * length
        # For every character in the string of the new specimen, a lottery number is chosen at random from 0 to 1. If
        # the lottery number is below the input variable mutation_rate then that character is 'mutated' and replaced
        # with a character randomly chosen from the printable ASCII letters list. If the lottery number is higher than
        # the mutation_rate then the character stays the same as the one assigned in the breeding.
        for j in range(0,length):
            lottery = random.random()
            if lottery < mutation_rate:
                newLetter = str(random.sample(letters, 1))
                myChars[j] = newLetter
            else:
                myChars[j] = str(new_pop[i].string[j])
        # This joins the characters into the new, potentially-mutated string and replaces the string of the new
        # population specimen.
        myStr = ''.join(myChars)
        new_pop[i].string = myStr

    return new_pop

def main():

    # This assigns number of specimen in a generation, the generation number and maximum fitness to 0 as well as the
    # maximum number of generations and the mutation rate for later on.
    pop_size = 300
    gen_num = 0
    max_fitness = 0
    max_gen = 5000
    mutation_rate = 0.01

    # This runs the input function to get the goal string from the user.
    goal, length, letters = goal_input(pop_size)

    # This runs the random population generator to randomly generate the first generation of specimen.
    current_pop = rand_pop_generator(length, pop_size, letters)

    # This while loop is for every generation of specimen until the goal string is found or the maximum number of
    # generations is reached.
    while max_fitness <=0.99 and gen_num<max_gen:
        # The number of the generation iterates.
        gen_num += 1

        # This runs the fitness rater function to determine each specimen's fitness.
        current_pop, max_fitness, max_ind, avg_fitness = rate_fitness(current_pop, pop_size, goal, length)

        # This prints the generations data to the command window.
        save_print_data(current_pop, gen_num, max_fitness, max_ind, avg_fitness)

        # This builds the mating pool for the next generation.
        mating_pool = build_mating_pool(current_pop, pop_size, max_fitness)

        # This breeds the new generation from the mating pool.
        new_pop = mating(mating_pool, current_pop, pop_size, length)

        # This randomly mutates the newly generated generation
        mutated_pop = mutation(new_pop, pop_size, length, mutation_rate, letters)

        # The newly generated and mutated population becomes the current population for the next generation.
        current_pop = mutated_pop

    # If the algorithm successfully replicated the goal string then it prints the string and how many generations it
    # took to replicate. If not is says that it could not replicate the goal string in the maximum number of
    # generations.
    if gen_num < max_gen:
        print(f"Replicated string '{goal}' in {gen_num} generations.")
    else:
        print(f"Program was not able to replicate string '{goal}' in {max_gen} generations")

# This runs the script
if __name__ == '__main__':

    main()



