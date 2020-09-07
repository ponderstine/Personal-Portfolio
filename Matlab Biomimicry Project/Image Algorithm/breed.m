function child=breed(parent1,parent2)
% %% Method 1
% %The function starts by setting the child equal to the second parent. The child is currently 
% %100 percent identical to the second parent 
% child = parent2;
% %The size of the first parent is assigned to the variable len
% siz = numel(parent1);
% %A new matrix of random integers is created and is equal to the size of
% %size
% split = randi([siz]);
% %The function cuts the "split" matrix into two and rounds to the nearest
% %integer. Next, the function will check each value and the child will get
% %half of the correct values from the first parent. By this point, the child
% %now has half of its DNA from each parent. 
% for i=1:round(split/2)
%     child(i) = [parent1(i)];
% end


%% Method 2
%The function first measures the size of the parent image
siz = size(parent1);
%The child is then created to be the same size as the parent image, but the
%child's matrix is a zeros matrix and of unit8 type. 
child =uint8(zeros(siz));
%A logical matrix of random order between 0's and 1's is created and is the
%same size as the child and the parent
logic = randi([0,1],siz);
%The function goes through each element of the logical matrix and uses it
%to compare between the first parent and the child. 
for i =1:numel(logic)
%If the logical matrix element is equal to one, then the same respective element of the child
%will be reassigned to be the same as the value in that respective element
%of the first parent.  
    if logic(i)==1
        child(i) = parent1(i);
    else
%For all zeros in the logical matrix, the child will
%be assigned the values of the second parent.
        child(i) = parent2(i);
    end
end

end