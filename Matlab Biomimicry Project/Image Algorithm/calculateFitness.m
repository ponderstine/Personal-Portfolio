function [fitness,maxFitness,avgFitness,bestImgIndex] = calculateFitness(population,target,populationSize,tolerance)

%This function will calculate the initial fitness of each member in the
%population by comparing each string to the target string. This will also
%calculate the max fitness and the average fitness of each generation.

% Preallocates space for the logic vector that will store the number of
% characters correct in each string
logic = zeros(size(target));
fitness=zeros(populationSize,1,3);
% The function counts the number of elements in the target matrix
num=numel(target);
% The target is reassigned to type double
compare=double(target);


% Calculates the number of characters correct in each string and saves to
% the logic vector
for i = 1:populationSize
% The function reassigns each variable in temp to the type double
    temp = double(population{i});
    logic=logic*0;
    for j =1:num
% The function checks if the difference between each element in the temp
% and the target falls within the designated tolerance. If the difference
% is within the tolerance, then the new value is kept. 
       if abs(temp(j)-compare(j))<=tolerance
            logic(j)=1;
       end
    end
    fitness(i,1,:)=sum(sum(logic),2);
end
%Multiply by 3 in order to account for the 3 RGB channels of each element
%and then divide by the number of elements
fitness=fitness*3/num;

% Finds the max fitness in the population
maxFitnessRGB = max(fitness);
maxFitness = (maxFitnessRGB(1)+maxFitnessRGB(2)+maxFitnessRGB(3))/3;

% Calculates the average fitness of the population
avgFitnessRGB = sum(fitness)/populationSize;
avgFitness = (avgFitnessRGB(1)+avgFitnessRGB(2)+avgFitnessRGB(3))/3;

% Finds the phrase that had the max fitness of the population
bestImgIndex = find(fitness == maxFitnessRGB,1);

end