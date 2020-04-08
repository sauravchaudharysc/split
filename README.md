# Splitwise App Algorithm
![](split.png)</br>
An Easy Example to Example To Explain It:- </br>
Let us assume there are three persons:- A,B and C</br>
A owes B 100 Rupees</br>
B owes C 50 Rupees</br>
C owes A 40 Rupees</br>

Here in the end each person will be in debit mode or credit mode.</br>
To simplify transaction we need total Net Amount.</br>

Here,</br>
 A is losing 100 and gaining 40 :- -60</br>
 B is losing 50 and gaining 100 :-  50</br>
 C is losing 40 and gaining 50  :-  10</br>
</br>
Lets try to settle these amount:-</br>
Debit Mode   Credit Mode</br>
A -60         B 50</br>
	      C 10</br>
 
So here we choose the largest debiter and try to settle the largest crediter.
I will take 50 rupees from A and settle the credit of B. So doing this A will 
have 10 Rupees. Now we choose the largest crediter.Once we have 2 people we will
observe net amount of debit will be equal to amount of credit. So A will give 
10 Rupees to C. So doing this we solve it in 2 Transaction.

## PseudoCode 
1.Make a list of people who want to debit.</br>
2.Make a list of people who want to credit.</br>

And we pick a person who is the highest debiter and try to settle as many person by
picking the highest crediters. You can make a max heap for both of them.So if we this
approach then complexity will be nlogn and if linear search then n^2.

### An Implementation with different data structure.

## MultiSet
MultiSet is a set that contains multiple element with the same value.

![](multiset.png)</br>
Take two pointers:-</br>
Low and High.</br>
The left are debiters and right are crediters.</br>
We can pick the smallest number and try to settle the highest number for right.
So this will help to settle transaction. </br>
		=> min(abs|-60|,50)</br>
		=> 50</br>
low = low+50 = -10</br>
high = high-50 = 0</br>
For zero we remove it to remove completed transaction.</br>
Then,</br>
 low = -10</br>
 high = 10</br>
We can pick the smallest number and try to settle the highest number for right.
So this will help to settle transaction.</br> 
		=> min(abs|-10|,10)</br>
		=> 10</br>
 low = low+10 = 0</br>
 high = high-10 = 0</br>
Finally we will have zero entry in the multiset and this make sure there is no 
pending transaction. 
