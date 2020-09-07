function matingPool = buildMatingPool(fitness,maxFitness,matingPoolFactor,populationSize)

%This function builds the mating pool from the population, its fitness, and
%the mating pool factor. The fitness will be multiplied by the mating pool
%factor to determine how many times each member will be put into the mating
%pool. Then each member of the population will be replicated the correct
%number of times into the mating pool.

%maxFitMat = repmat(maxFitness,populationSize);

normalFitness = (fitness./maxFitness).^4;

%calculate how many tickets each member will get
if maxFitness ~=0
    tickets = round(normalFitness * matingPoolFactor);
else
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