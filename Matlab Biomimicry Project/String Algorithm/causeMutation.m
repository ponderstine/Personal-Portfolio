function population = causeMutation(child,mutationRate,targetSize)

%This function will randomely mutate the new children at a given rate. This
%function will use the new children and the mutation rate to cause
%mutations.

randNum = rand();

%If the variable randNum is less than the mutation rate, then the new
%variable temp will be character string of random characters on the ASCII
%table from values 32 to 122 (from SPACE bar to lower case z). 
if randNum<=mutationRate
    temp = char(randi([32,122],1,targetSize));
else
%If the randNum variable is greater than the mutation rate, then the temp variable
%will be equal to the child. 
    temp=child;
end
%The new population for the function to work with will be the temp
%variable. 
population = temp;

end