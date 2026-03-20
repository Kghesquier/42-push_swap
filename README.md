*This project has been created as part
of the 42 curriculum by kghesqui.*

# PUSH_SWAP

## DESCRIPTION :

Push_swap is a sorting algorithm project where we must sort a stack of integers using only two stacks (a and b) and a limited set of operations (swap, push, rotate, reverse rotate). Our goal is to sort stack a in ascending order using the minimum number of operations. The challenge lies in implementing an efficient algorithm where we calculate the "cost" of moving each element and always choose the cheapest move. We also optimize double rotations (rr/rrr) when both stacks need to rotate in the same direction, combining two operations into one to minimize the total operation count.

## INSTRUCTIONS :

For compilation and execution there is a Makefile with the commands : `make all, clean, fclean and re`. the command make compiles all the sources files using `cc` with the following flags : `-Wall -Werror -Wextra -I.`

## RESOURCES :

### Here is some of the websites I visited for this project :
https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
https://42-cursus.gitbook.io/guide/2-rank-02/push_swap
https://medium.com/@dansylvain84/my-implementation-of-the-42-push-swap-project-2706fd8c2e9f
https://www.reddit.com/r/42_school/comments/1ob6zcp/push_swap_algorithm/?tl=fr
https://dynamicdispat.ch/posts/2024/01/push-swap/
https://medium.com/@ayogun/push-swap-c1f5d2d41e97
https://stackoverflow.com/questions/75100698/push-swap-what-is-the-most-efficient-way-to-sort-given-values-using-a-limited-s
https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

### and the GitHub repos I watched to get some inspos :
https://github.com/Hqndler/42-push_swap
https://github.com/stevebalk/push-swap-clicker
https://github.com/42YerevanProjects/push_swap
https://github.com/TheRedShip/42-push-swap

Regarding AI, I didn't used it that much in the project itself but I asked claude code to review my program to be sure and to make some tests. I do my own test when I code but when it's finished I ask claude code and run francinette. I also used claude to help me for the graphical things that can be present in the `README.md` file. For this project I also ask claude to help me to plannify and to clarify every steps. I give it what I wanted to do in details and he gave me a plan (where to start and where to finish). I asked that to gain some time and to make it clearer in my mind cause there is a lot of step for this project compared to the previous ones.