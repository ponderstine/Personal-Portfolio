function [fitness,maxFitness,avgFitness,bestPhrase] = calculateFitness(population,target,populationSize)

%This function will calculate the initial fitness of each member in the
%population by comparing each string to the target string. This will also
%calculate the max fitness and the average fitness of each generation.

% Preallocates space for the comparison cell array
compare = cell(populationSize,1);

% Creates a cell array the same size as the population cell, except full of
% the target string
for i =1:populationSize
   compare{i} = target;
end

% Preallocates space for the logic vector that will store the number of
% characters correct in each string
logic = zeros(populationSize,1);

% Calculates the number of characters correct in each string and saves to
% the logic vector
for i = 1:populationSize
    logic(i) = sum(population{i} == compare{i});
end
       
% Calculates fitness as a percentage of characters that are correct
fitness = logic / length(target);

% Finds the max fitness in the population
maxFitness = max(fitness);

% Calculates the average fitness of the population
avgFitness = sum(fitness)/populationSize;

% Finds the phrase that had the max fitness of the population
bestPhrase = population{find(fitness == maxFitness,1)};

end