% Genetic algorithm project Skeleton code by Zachary Vanlangendonck and
% Ponder Stine.

clear;clc;
rng('shuffle')

%%Define Target

%menu for user to select which image they want to set as the target
image_choice = menu('Choose an image', 'Calendar', 'Wifi', 'Guy', 'Angry Emoji',...
    'Poop Emoji', 'Mona Lisa (small)', 'Mona Lisa (medium)', 'Mona Lisa (large)');
           switch image_choice
               case 1
                   filename = '10x10cal.jpg';
               case 2
                   filename = '10x10wifi.jpg'; 
               case 3
                   filename = '24x24guy.jpg'; 
               case 4
                   filename = '25x25angry.png';
               case 5
                   filename = '25x25poop.png';
               case 6
                   filename = '36x36monalisa.jpg';
               case 7
                   filename = '50x50monalisa.jpg';
               case 8
                   filename = '64x64monalisa.jpg';
           end

%Defining what our target is, and what we want out poplation to evolve
%towards
target = imread(filename);
targetSize = size(target);

%Defining the maximum number of generations that the program will run
maxGenNum = 10000;
i=1;

%Create data matrix that will store the data from each generation
data = zeros(maxGenNum,4);

%First column of data matrix is Generation Number 
data(:,1) = 0:maxGenNum-1;

%initialize cell array of best members
best = cell(maxGenNum,1);

%% Generate initial population

%Define size of population (# of strings)
populationSize = 1500;

% This function creates a random population of equal length strings. The
% number of strings in the population can be manipulated.
population = buildPopulation(populationSize,targetSize);

%% Algorithm

% This for loop is the beginning of the genetic algorithm where new
% generations will be breeded based on fitness of previous generation

maxFitness = 0;

while (i<maxGenNum && maxFitness <.97)
    %% Calculate Fitness

    %Tolerance between target pixel values and generated pixel values
    tolerance = 7;
    
    % Calculate fitness (%) of population by comparing it to the target. The
    %fitness of a string is how many characters it shares with the target
    %string
    [fitness,maxFitness,avgFitness,bestImgIndex] = calculateFitness(population,target,populationSize,tolerance);
    
    %% Save data from generation

    %save data to matrices
    best{i} = population{bestImgIndex};
    data(i,2) = maxFitness;
    data(i,3) = avgFitness;
    data(i,4) = maxFitness - avgFitness;

    %% Build a mating pool

    %Create a mating pool factor that can easily be change later
    matingPoolFactor = 10;

    %Create mating pool using population, fitness, and mating factor
    redPool = buildMatingPool(fitness(:,:,1),maxFitness,matingPoolFactor,populationSize);
    greenPool = buildMatingPool(fitness(:,:,2),maxFitness,matingPoolFactor,populationSize);
    bluePool = buildMatingPool(fitness(:,:,3),maxFitness,matingPoolFactor,populationSize);
    
    %% Breed a new population

    for j=1:populationSize
        
        %Randomly select parents for the RGB channels
        red1 = randi([1,length(redPool)]);
        red2 = randi([1,length(redPool)]);
        green1 = randi([1,length(greenPool)]);
        green2 = randi([1,length(greenPool)]);
        blue1 = randi([1,length(bluePool)]);
        blue2 = randi([1,length(bluePool)]);
        
        %Find the parents for thr RGB channels to breed the new member
        redParent1=cell2mat(population(redPool(red1)));
        redParent2=cell2mat(population(redPool(red2)));
        greenParent1=cell2mat(population(greenPool(green1)));
        greenParent2=cell2mat(population(greenPool(green2)));
        blueParent1=cell2mat(population(bluePool(blue1)));
        blueParent2=cell2mat(population(bluePool(blue2)));
        
        % Breed new RGB channels from parents
        redChild = breed(redParent1(:,:,1),redParent2(:,:,1));
        greenChild = breed(greenParent1(:,:,2),greenParent2(:,:,2));
        blueChild = breed(blueParent1(:,:,3),blueParent2(:,:,3));
        
        %initialize child matrix
        child = uint8(zeros(targetSize));
        
        %concatenate channels to make new child
        child(:,:,1)=redChild;
        child(:,:,2)=greenChild;
        child(:,:,3)=blueChild;        

        % Define mutation rate
        mutationRate = 0.025;
        brightMutVal = 30;

        % Mutate child randomly and replace the current population with the new
        % generation
        population{j} = causeMutation(child,mutationRate,brightMutVal);
    end
    fprintf('Gen. #%d, Max fitness %.4f, Avg Fitness %.4f\n',i,maxFitness,avgFitness);
    i=i+1;
end
        
%% Save data to text file

%trim vectors to delete section without data
data(i:end,:) = [];
best(i:end,:) = [];

%Format data to save to text file
genNum = data(:,1);
maxFit = (round(data(:,2)*100000))/100000;
avgFit = (round(data(:,3)*100000))/100000;

%write table with data
geneticData = table(genNum,maxFit,avgFit);

%save table of data to text file
writetable(geneticData,'geneticData.txt','Delimiter','\t')

%save best population member to an image file
imwrite(best{i-1},'BestComputerGeneratedImage.jpg')

%% Plot data

%Plot 9 images of members evenly space throughout the run
subplot(3,3,1), imshow(best{1});
title('Generation 1');
subplot(3,3,2), imshow(best{round(i/8)});
string=sprintf('Generation %d',round(i/8));
title(string);
subplot(3,3,3), imshow(best{round(i/4)});
string=sprintf('Generation %d',round(i/4));
title(string);
subplot(3,3,4), imshow(best{round(3*i/8)});
string=sprintf('Generation %d',round(3*i/8));
title(string);
subplot(3,3,5), imshow(best{round(i/2)});
string=sprintf('Generation %d',round(i/2));
title(string);
subplot(3,3,6), imshow(best{round(5*i/8)});
string=sprintf('Generation %d',round(5*i/8));
title(string);
subplot(3,3,7), imshow(best{round(3*i/4)});
string=sprintf('Generation %d',round(3*i/4));
title(string);
subplot(3,3,8), imshow(best{round(7*i/8)});
string=sprintf('Generation %d',round(7*i/8));
title(string);
subplot(3,3,9), imshow(best{i-1});
string=sprintf('Generation %d',i-1);
title(string);