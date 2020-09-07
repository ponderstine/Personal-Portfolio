% Genetic algorithm project Skeleton code by Zachary Vanlangendonck and
% Ponder Stine.

clear;clc;
rng('shuffle')

%%Define Target

%Defining what our target is, and what we want out poplation to evolve
%towards
target = 'Hello world';
targetSize = length(target);

%Defining the maximum number of generations that the program will run
maxGenNum = 10000;
i=1;

%Create data matrix that will store the data from each generation
data = zeros(maxGenNum,4);
best = cellstr(char(zeros(maxGenNum,1)));

%First column of data matrix is Generation Number 
data(:,1) = [0:maxGenNum-1]';

%% Generate initial population

%Define size of population (# of strings)
populationSize = 200;

% This function creates a random population of equal length strings. The
% number of strings in the population can be manipulated.
population = buildPopulation(populationSize,targetSize);

%% Algorithm

% This for loop is the beginning of the genetic algorithm where new
% generations will be breeded based on fitness of previous generation

maxFitness = 0;

while (i<maxGenNum && maxFitness < 1)
    %% Calculate Fitness

    %Calculate fitness (%) of population by comparing it to the target. The
    %fitness of a string is how many characters it shares with the target
    %string
    [fitness,maxFitness,avgFitness,bestPhrase] = calculateFitness(population,target,populationSize);
    
    %% Save data from generation

    best(i) = cellstr(bestPhrase);
    data(i,2) = maxFitness;
    data(i,3) = avgFitness;
    data(i,4) = maxFitness - avgFitness;

    %% Build a mating pool

    %Create a mating pool factor that can easily be changed later
    matingPoolFactor = 10;

    %Create mating pool using population, fitness, and mating factor
    matingPool = buildMatingPool(fitness,maxFitness,matingPoolFactor,populationSize);

    %% Breed a new population

    for j=1:populationSize
        
        %choosing parents for the new population member
        index1 = randi([1,length(matingPool)]);
        index2 = randi([1,length(matingPool)]);
        
        %Finding the new parents genetic data
        parent1=char(population(matingPool(index1)));
        parent2=char(population(matingPool(index2)));
        
        % Breed new child from 2 parents
        child = breed(parent1,parent2);

        % Define mutation rate
        mutationRate = 0.025;

        % Mutate child randomly and replace the current population with the new
        % generation
        population{j} = causeMutation(child,mutationRate,targetSize);
    end
    
    %print to screen gen #, max fitness, avg fitness, and best phrase
    fprintf('Gen. #%d, Max fitness %.4f, Avg Fitness %.4f, Best phrase: %s\n',i,maxFitness,avgFitness,bestPhrase);
    
    %increment gen number
    i=i+1;
end
        
%% Save data to text file

%delete empty rows
data(i:end,:) = [];
best(i:end,:) = [];

%Manipulate date to be presented in the text file
bestPhrase = char(best);
genNum = data(:,1);
maxFit = (round(data(:,2)*100000))/100000;
avgFit = (round(data(:,3)*100000))/100000;

%create a table with the data
geneticData = table(genNum,maxFit,avgFit,bestPhrase);

%save the table of data to a text file
writetable(geneticData,'geneticData.txt','Delimiter','\t')

%% Plot data

%define vaiables
x= 1:i-1;
y1=data(x,2);
y2=data(x,3);

%plot max and avg fitness
plot(x,y1), hold
plot(x,y2)

%Format titles, axis labels, and legend
title('Max and Avg Fitness Through Generations')
xlabel('Generations')
ylabel('Fitness')
legend('Max Fitness','Avg Fitness','location','northwest')
