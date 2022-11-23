## What does wait() return? 
On success, wait() returns the ID of the terminated child process, otherwise it returns -1.
## What happens if you use wait() in the child?
If the child has no child process (didn't fork()), nothing happens and wait() returns -1. If the child has a child (did fork()), it will return its ID.