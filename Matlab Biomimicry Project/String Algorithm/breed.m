function child=breed(parent1,parent2)

%This function takes the strings of both parents and pulls values from them
%to "breed" - or make - a new string designated as the child. The function
%performs in one of two methods: the first method encompasses the function
%copying one parent and placing values from the other parent in the copy
%and the second method goes through each value of a child of random values
%and reassigns the values based on which are equal to each parent. 

%% Method 1
% %The function starts by setting the child equal to the second parent. The child is currently 
% %100 percent identical to the second parent 
% child = parent2;
% %The length of the first parent is assigned to the variable len
% len = length(parent1);
% %A new vector of random integers is created and is equal to the length of
% %len
% split = randi([1,len]);
% %The function cuts the "split" vector into two and rounds to the nearest
% %integer. Next, the function will check each value and the child will get
% %half of the correct values from the first parent. By this point, the child
% %now has half of its DNA from each parent. 
% for i=1:round(split/2)
%     child(i) = [parent1(i)];
% end

%% Method 2
%Since both parents are the same length, the length of only one parent is
%needed. 
len = length(parent1);
%The child will be a character string of just ones but of the same length
%as the parent.
child =char(32*ones(1,len));
%A new random vector is created of the same length as the parent and each value is rounded to the nearest integer.  
logic = round(rand(1,len));
%The function will check each individual element of both the parent and the
%child and decide which values the child emulates with respect to each
%parent. 
for i =1:len
    if logic(i)==1
        child(i) = parent1(i);
    else
        child(i) = parent2(i);
    end
end

end