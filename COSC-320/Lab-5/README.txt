Daniel Weitman
3/14/19
COSC-320

(a)
First the enqueue checks if there is enough heap capacity to add another element.
Then enqueue assigns the obj and priority into the next leaf node of the heap and goes up as far as the key permits in keeping with increasekey. Dequeue starts by checking if there are any elements in the heap and if there are then dequeue, removes the item off the top of heap and calls maxheapify to correct the rest. Otherwise the methods are fairly trivial for 320.

(b)
Enqueue
Worst case: n
Average case: logn
Best case: 1

Dequeue
Worst case: n
Average case: logn
Best case: logn

(c)
1000
E: .000001496
D: .000002581
10000
E: .000000665
D: .000002832
100000
E: .000001016
D: .00001217
1000000
E: .000001528
D: .000006723


(d)
A priority queue could be used in a web server to allow more important users get access to the server first and prevents clogs in the server by allowing users through, this is better than a normal queue because it allows users to bypass solely FIFO format. 

A CPU could utilize a priority queue to prioritize more important processes that could cause system malfunctions if they are not dealt with in a timely manner. This works better than a normal queue or stack because it ensures that the processes that need to be completed fast are done.



(e)
Add some more options on the HeapQueue for special access permissions. 

