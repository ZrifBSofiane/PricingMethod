# PricingMethod
Options Pricing Method 


Here is the UML :

![alt uml](http://sofiane-zrif-bouragba.com/blog/wp-content/uploads/2018/01/UMLProject.png)


# Pricer Class

I make one class for each pricer method. In fact, all pricer works with an Option Class. 
At the beginning, the pricer needed all the data to works. But because i developped Option Abstract Class, it's more easy to work with it for the pricer.

I can add that because Option is abstract, it must have virtual method, but which one ? Obviously the payoff method. Each Option has his own payoff.

# How to use the algo ? 

That's pretty easy. First you have to give some data that are printed on the screen. Then you choose which Option we want to price. And finally, let's run the computer :) 

Basically, when you give an answer which does not correspond to all the propositions, it will take one of them automatically. 
 
# Bonus ? 
I choose to do the first Bonus from the TD9 which is A.

Moreover, there an class named BinLattice which represent a binomial tree. It was developped with a Template, so it can store whatever you want. 
# Contributors 

This project was made by group XX composed by me BOURAGBA SOFIANE and JASAWANT NAIME GAEL
