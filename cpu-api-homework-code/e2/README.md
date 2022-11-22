## Can both the child and parent access the file descriptor returned by open()?
Yes. The child has the same file descriptor table as the parent before the fork.
## What happens when they are writing to the file concurrently, i.e., at the same time?
The writting will be random.