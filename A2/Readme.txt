How to run?
1. place your submission into ./sub/
2. bash grading.sh
It will give your grade out of 95%.

How I will evaluate style?
1. If main return type is void not int: -1;
2. I will use splint to check the following bad styles. As splint may output false positive, only the same problem occurs 5 times result -1.
	out-of-bounds, incompatible types, size_t gets int, Assignment of int to char, possibly null
3. Even though the max deduction is -6 according the above rules, the minium possible style grade is 0. 