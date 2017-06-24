// Sum and Average of Odd Numbers

A=[23 44 2 -4 -19 15 1 -70 78];
sum = 0;
N_odds = 0;
for k=1:numel(A)
    if mod(A(k),2)
        sum=sum+A(k);
        N_odds = N_odds + 1;
    end
end
my_average = sum/N_odds;

// Find 2 numbers in array to na given number x

http:www.geeksforgeeks.org/find-k-closest-elements-given-value/
