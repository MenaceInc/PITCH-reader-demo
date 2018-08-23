Write a program which reads PITCH data from standard input and, at the end of the input, shows a table of the top ten symbols by executed volume.  
For example, your table should look something like this:  
  
    SPY   24486275  
    QQQQ  15996041  
    XLF   10947444  
    IWM    9362518  
    MSFT   8499146  
    DUG    8220682  
    C      6756932  
    F      6679883  
    EDS    6673983  
    QID    6526201  
  
The PITCH specification is available from our website here: http://cdn.batstrading.com/resources/membership/BATS_US_EQUITIES_TCP_PITCH_SPECIFICATION.pdf  
  
In short, you'll need to read Add Order messages and remember what orders are open so you can apply Order Cancel and Order Executed messages.  
Trade Messages are sent for orders which were hidden.  
You'll need to use both Order Executed and Trade Messages to compute total volume.  
For simplicity, ignore any Trade Break and long messages (‘B’, ‘r’, ‘d’).  
  
I've included a portion of live PITCH data in a file named pitch_example_data.gz.  
(Note that each line in the sample file begins with an extra character, 'S', not mentioned in the specification. This character is not part of the message and should be skipped by your program.)  
  
Take as much or as little time solving the problem as you'd like.  
Try to write code that is "production quality" (make it efficient, make sure it doesn't leak memory, etc.).  
Use standard, cross-platform C++.  
You can use components from the STL and Boost.  
  
