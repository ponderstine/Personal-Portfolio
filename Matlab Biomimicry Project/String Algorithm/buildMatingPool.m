function matingPool = buildMatingPool(fitness,maxFitness,matingPoolFactor,populationSize)

%This function builds the mating pool from the population, its fitness, and
%the mating pool factor. The fitness will be multiplied by the mating pool
%factor to determine how many times each member will be put into the mating
%pool. Then each member of the population will be replicated the correct
%number of times into the mating pool.

%create matrix filled with the max fitness that will be used to calculate
%normalized fitness
maxFitMat = repmat(maxFitness,populationSize,1);

%calculate normalized fitness by dividing all fitnesses by the max fitness
%then cubing the value
normalFitness = (fitness./maxFitMat).^3;

%calculate how many tickets each member will get
if maxFitness ~=0
    tickets = floor(normalFitness * matingPoolFactor);
else
    %if all fitness = 0, all members get 1 ticket
    tickets = fitness+1;
end

%initialize the matrix of tickets
temp = [];

%add the specified number of tickets for each member into a temp variable
for i = 1:populationSize
    add = repmat(i,1,tickets(i));
    temp = [temp,add];
end

%output the matrix of tickets
matingPool = temp;    
    
end