# AsyncTask
A set of classes which provides utilities for asynchrnous programming in a manageable manner. 

#### Class Task

A class which wraps the functionality of std::function and provides a callable object.

To wrap the following function:

```
void testFunction(int x, int y){
	std::cout << x << " and " << y << std::endl;
}
```

One can create a Task object and pass the function to it:

```
Task<int, int> taskObj(testFunction);
```

Then use the prepared object:
```
taskObj(3, 4);

or 

# Parameters to be passed to testFunction()
int num1 = 2;
int num2 = 4;
taskObj(num1, num2);
```


#### Class TaskManager

TaskManager is a task dispatcher class. It starts a thread and waits for tasks to be added into the queue.

To run a task in a separate thread:

```
TaskManager tm;

# Add a task into queue
tm<int,int>.AddTask(taskObj, 3, 4);

```


#### Class AsyncTask

AsyncTask provides a functionality to run a task in a separate thread context owned by TaskManager object. It also provides a callable object. The task is queued in task manager when the async object is called.

To run a task asynchronously:

```
# Create a shared pointer of task manager
TaskManagerPtr tmPtr = std::make_shared<TaskManager>();

AsyncTask<int, int> myTask(testFunction, tmPtr);

# Run the task asynchronously
myTask(5, 12);

```


#### Class ChangeThreadContext

ChangeThreadContext provides a functionality to run a task in a separate thread context owned by TaskManager object. It queues the task right at the time of object instatiation.

To run a task asynchronously:

```
# Create a shared pointer of task manager
TaskManagerPtr tmPtr = std::make_shared<TaskManager>();

# Parameters to be passed to testFunction()
int x = 12;
int y = 13;

# Run the task asynchronously
ChangeThreadContext<int, int> thread(std::bind(testFunction, x, y), tmPtr);
```


----
### Samples

Sample source files demonstrating the aforementioned classes are provided in the *src* folder.

#### Build

To build the source code, follow the steps:

```
git clone https://github.com/ashubhatt/AsyncTask.git
cd AsyncTask
mkdir build && cd build
cmake ../
make -j4
```
All the generated binaries will be available under *build/bin* directory.
