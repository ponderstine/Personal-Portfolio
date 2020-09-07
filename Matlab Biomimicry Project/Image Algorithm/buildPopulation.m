function population = buildPopulation(populationSize,targetSize)

%This function will build the initial population of random values. The
%strings will be the correct length as the target by using the targetSize
%variable.

%Initialize a cell array with the correct number of elements for the
%desired size of the population
population = cell(populationSize,1);

% Going element by element, fill in the cell array with random images
for i = 1:populationSize
    population{i} = uint8(randi([0,255],targetSize));
end


end