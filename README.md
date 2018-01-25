# PricingMethod
Options Pricing Method 


Here is the UML :

![alt uml](http://sofiane-zrif-bouragba.com/blog/wp-content/uploads/2018/01/UMLProject.png)


# Pricer Class

I make one class for each pricer method. In fact, all pricer works with an Option Class. 
At the beginning, the pricer needed all the data to works. But because i developped Option Abstract Class, it's more easy to work with it for the pricer.

I can add that because Option is abstract, it must have virtual method, but which one ? Obviously the payoff method. Each Option has his own payoff.
 
