function population = causeMutation(child,mutationRate,brightMutVal)

%This function will randomely mutate the new children at a given rate. This
%function will use the new children and the mutation rate to cause
%mutations.

%A random value is generated
r=rand();
%If the random value is less than the mutation, then the function goes
%through each element of the child and checks if the random value is less
%than .25, and then reassigns the child a random integer value from 0 to
%255. If the random value does not meet these conditions, then the function
%assigns the child random values from brightMutVal.
if rand()<=mutationRate
    for i = 1:numel(child)
        if rand()<=.25
            child(i)=randi([0,255]);
        else
            child(i)=child(1)+randi([-brightMutVal,brightMutVal]);
        end
    end
end
%The end population is the child. 
population=child;

end