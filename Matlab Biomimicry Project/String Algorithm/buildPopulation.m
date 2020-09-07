function population = buildPopulation(populationSize,targetSize)

%This function will build the initial population of random values. The
%strings will be the correct length as the target by using the targetSize
%variable.

% Initialize a cell array with the correct number of elements for the
%desired size of the population
temp = cell(populationSize,1);

% Going element by element, fill in the cell array with random integers in
% the desired ASCII range and the same length as the target phrase that
% are then converted to character strings
for i = 1:populationSize
    temp{i} = randi([32,122],1,targetSize);
    
    %converts random integers to character strings using ASCII character
    %conversion
    temp{i} = char(temp{i});
end

% Return the initial population after it has been created
population = temp;


end