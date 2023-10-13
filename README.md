Overview
The Project Management System is a command-line application designed to assist users in managing and scheduling tasks within a project. It allows users to define tasks, assign resources, track dependencies, calculate schedules, and analyze project timelines. This is a C++ program that implements the Critical Path Method (CPM) for project scheduling. The program allows you to define tasks, dependencies, resources, and skill proficiency to calculate the critical path and project completion time. It provides a menu-based interface for performing various actions related to project scheduling.
Features
•	Task Management: Create, modify, and manage tasks with details like ID, duration, dependencies, skills, and resource requirements.
•	Resource Allocation: Assign resources to tasks, specifying the required skill and availability.
•	Dependency Tracking: Define task dependencies to establish the order in which tasks must be completed.
•	Scheduling: Calculate and display the basic project schedule, including earliest start and finish times, latest start and finish times, and slack.
•	Critical Path Analysis: Identify the critical path of the project, highlighting tasks that, if delayed, would impact the project's completion date.
•	Resource Proficiency: Calculate project completion times based on the proficiency of assigned resources.
Usage
•	Adding Resources: Add resources to the project, specifying their skills and availability.
•	Creating Tasks: Define tasks, setting details such as duration, dependencies, required skills, and resource assignments.
•	Task Scheduling: Calculate the project's basic schedule to understand task start and finish times and identify the critical path.
•	Resource Allocation: Assign resources to tasks, ensuring that they possess the required skills.
•	Proficiency Analysis: Evaluate project completion times by considering the proficiency levels of assigned resources.
•	Dependency Management: Manage task dependencies to ensure that tasks are executed in the correct order.
•	Project Analysis: Analyze project timelines and critical paths to make informed decisions about resource allocation and task prioritization.
Menu Options
1.	Add Resources: Add resources to the project, along with their skills and proficiency.
2.	Add Task: Add tasks to the project, specifying task duration, dependencies, and required skills.
3.	Set Task Duration: Set the duration of each task in the project.
4.	Set nth Task Duration: Set the duration of a specific task.
5.	Print Task Dependency List: Display the list of tasks and their dependencies.
6.	Calculate Basic Schedule: Calculate the project schedule with the CPM method.
7.	Print Critical Path: Display the critical path of the project.
8.	Completion Time with Resources: Calculate the project completion time considering resources.
9.	Completion Time with Resource Proficiency: Calculate the project completion time considering resource proficiency.
10.	Exit: Exit the program.
Classes
Skill Class
The Skill class represents a skill with an ID and proficiency level.
Properties
•	id (int): An identifier for the skill.
•	proficiency (float): The proficiency level of the skill.
Constructors
•	Skill(): Initializes a skill with default values (ID = 0, proficiency = 0.0).
•	Skill(int id, float proficiency): Initializes a skill with the specified ID and proficiency.
Methods
•	int getId(): Returns the ID of the skill.
•	float getProficiency(): Returns the proficiency level of the skill.
•	void setId(int id): Sets the ID of the skill.
•	void setProficiency(float proficiency): Sets the proficiency level of the skill.
SkillNode Class
The SkillNode class is a node for creating a linked list of skills.
Properties
•	skill (Skill*): A pointer to a Skill object.
•	next (SkillNode*): A pointer to the next SkillNode in the linked list.
Constructors
•	SkillNode(): Initializes a SkillNode with no skill and no reference to the next node.
•	SkillNode(Skill* skill): Initializes a SkillNode with a pointer to a Skill and no reference to the next node.
Methods
•	Skill* getSkill(): Returns the pointer to the Skill object stored in the node.
•	SkillNode* getNext(): Returns a pointer to the next SkillNode in the linked list.
•	void setSkill(Skill* skill): Sets the Skill object that the node points to.
•	void setNext(SkillNode* next): Sets the next SkillNode in the linked list.
Resource Class
The Resource class represents a resource with an ID, availability status, associated skills, and a reference to the next resource in a linked list.
Properties
•	id (int): An identifier for the resource.
•	availability (bool): Indicates whether the resource is available (default is true).
•	skills (SkillNode*): A pointer to the head of a linked list of SkillNode objects, representing the skills associated with the resource.
•	next (Resource*): A pointer to the next resource in the linked list.
Constructors
•	Resource(): Initializes a resource with default values (ID = 0, availability = true, no associated skills, and no reference to the next resource).
•	Resource(int id): Initializes a resource with the specified ID, default availability, no associated skills, and no reference to the next resource.
•	Resource(int id, bool availability): Initializes a resource with the specified ID, availability status, no associated skills, and no reference to the next resource.
Methods
•	int getId(): Returns the ID of the resource.
•	bool getAvailability(): Returns the availability status of the resource.
•	SkillNode* getSkills(): Returns a pointer to the linked list of SkillNode objects representing the skills associated with the resource.
•	Resource* getNext(): Returns a pointer to the next resource in the linked list.
•	Setters
•	void setId(int id): Sets the ID of the resource.
•	void setAvailability(bool availability): Sets the availability status of the resource.
•	void setSkills(SkillNode* skills): Sets the linked list of SkillNode objects representing the skills associated with the resource. If the resource already has skills, the new skills are added to the end of the existing list.
•	void setNext(Resource* next): Sets the reference to the next resource in the linked list.
Task Class
The Task class represents a task with various attributes, including its ID, duration, scheduling information, dependencies, successor tasks, required skill, and a required resource ID.
Properties
•	id (int): An identifier for the task.
•	duration (int): The time required to complete the task.
•	earliestStart (int): The earliest time the task can start.
•	latestStart (int): The latest time the task can start without delaying the project.
•	slack (int): The amount of time the task can be delayed without delaying the project.
•	earliestFinish (int): The earliest time the task can finish.
•	latestFinish (int): The latest time the task can finish without delaying the project.
•	requiredSkill (Skill*): A pointer to the required skill for the task.
•	requiredResourceId (int): The ID of the required resource.
•	dependencies (Task*): A pointer to the head of a linked list of tasks representing the task's dependencies.
•	successor (Task*): A pointer to the head of a linked list of tasks that depend on this task.
•	allDependencies (Task*): A pointer to the head of a linked list of all tasks that this task depends on.
•	allSuccessors (Task*): A pointer to the head of a linked list of all tasks that depend on this task.
Constructors
•	Task(): Initializes a task with default values, including no dependencies, successors, skills, and a required resource.
•	Task(int id, int duration): Initializes a task with the specified ID, duration, and default values for other attributes.
Getters
•	int getId(): Returns the ID of the task.
•	int getDuration(): Returns the duration of the task.
•	Task* getDependencies(): Returns a pointer to the linked list of tasks representing the task's dependencies.
•	Task* getSuccessor(): Returns a pointer to the linked list of tasks that depend on this task.
•	int getEarliestStart(): Returns the earliest start time of the task.
•	int getLatestStart(): Returns the latest start time of the task.
•	int getSlack(): Returns the slack time of the task.
•	int getEarliestFinish(): Returns the earliest finish time of the task.
•	int getLatestFinish(): Returns the latest finish time of the task.
•	Skill* getRequiredSkill(): Returns the required skill for the task.
•	int getRequiredSkillId(): Returns the ID of the required skill, or 0 if there is no required skill.
•	int getRequiredResourceId(): Returns the ID of the required resource.
Setters
•	void setId(int id): Sets the ID of the task.
•	void setDuration(int duration): Sets the duration of the task.
•	void setDependencies(Task* dependencies): Sets the linked list of tasks representing the task's dependencies.
•	void setSuccessor(Task* successor): Sets the linked list of tasks that depend on this task.
•	void setEarliestStart(int earliestStart): Sets the earliest start time of the task.
•	void setLatestStart(int latestStart): Sets the latest start time of the task.
•	void setSlack(int slack): Sets the slack time of the task.
•	void setEarliestFinish(int earliestFinish): Sets the earliest finish time of the task.
•	void setLatestFinish(int latestFinish): Sets the latest finish time of the task.
•	void setRequiredSkill(Skill* requiredSkill): Sets the required skill for the task.
•	void setRequiredSkillId(int id): Sets the ID of the required skill or creates a new skill with the specified ID.
•	void setRequiredResourceId(int id): Sets the ID of the required resource.
TaskNode Class
The TaskNode class represents a node in a linked list of tasks.
Properties
•	task (Task*): A pointer to a Task object.
•	next (TaskNode*): A pointer to the next TaskNode in the linked list.
•	prev (TaskNode*): A pointer to the previous TaskNode in the linked list.
Constructors
•	TaskNode(): Initializes a TaskNode with no task, no next node, and no previous node.
•	TaskNode(Task* task): Initializes a TaskNode with a pointer to a Task object, no next node, and no previous node.
Getters
•	Task* getTask(): Returns the pointer to the Task object stored in the node.
•	TaskNode* getNext(): Returns a pointer to the next TaskNode in the linked list.
•	TaskNode* getPrev(): Returns a pointer to the previous TaskNode in the linked list.
Setters
•	void setTask(Task* task): Sets the Task object that the node points to.
•	void setNext(TaskNode* next): Sets the next TaskNode in the linked list.
•	void setPrev(TaskNode* prev): Sets the previous TaskNode in the linked list.
TaskList Class
The TaskList class represents a linked list of tasks.
Properties
•	head (TaskNode*): A pointer to the head (first node) of the linked list.
•	tail (TaskNode*): A pointer to the tail (last node) of the linked list.
Constructors
•	TaskList(): Initializes a TaskList with no head and no tail, representing an empty linked list.
Getters
•	TaskNode* getHead(): Returns a pointer to the head (first node) of the linked list.
•	TaskNode* getTail(): Returns a pointer to the tail (last node) of the linked list.
Setters
•	void setHead(TaskNode* head): Sets the head (first node) of the linked list.
•	void setTail(TaskNode* tail): Sets the tail (last node) of the linked list.
Methods
•	void addTask(Task* task): Adds a Task to the linked list. A new TaskNode is created for the task, and if the list is empty, it sets both the head and tail to this new node. If the list is not empty, it appends the new node to the end of the list, updating the tail accordingly.
Project
The Project class is a C++ class that manages a project by keeping track of tasks, resources, and performing various operations related to task scheduling, including calculating the Critical Path Method (CPM) and managing project completion time. The class contains methods for adding resources, adding tasks, setting task durations, calculating CPM, and more.
Properties
•	tasks (TaskList*): A pointer to a TaskList object containing a linked list of tasks.
•	resources (Resource*): A pointer to a Resource object, representing the resources available for the project.
•	startTime (int): The project's start time.
•	endTime (int): The project's end time.
Constructors
•	Project(): Initializes a project with an empty list of tasks, no resources, and default values for start and end times.
Getters
•	TaskList* getTasks(): Returns a pointer to the TaskList containing the project's tasks.
•	Resource* getResources(): Returns a pointer to the resources available for the project.
Setters
•	void setTasks(TaskList* tasks): Sets the TaskList object containing the project's tasks.
•	void setResources(Resource* resources): Sets the Resource object representing the project's resources.
Methods
•	addResource(Resource* resource): This function is used to add a resource to the project management system. It takes a pointer to a Resource as a parameter and adds it to the system. If no resources exist, it sets the resources attribute to the provided resource. If resources already exist, it appends the new resource to the end of the list.
•	addResource(): This function allows a user to interactively add a resource to the system. It prompts the user to enter a resource ID and a number of skills, checks for uniqueness of IDs and skill IDs, and adds the resource to the system.
•	addTask(Task* task): This function is used to add a task to the project management system. It takes a pointer to a Task as a parameter and adds it to the list of tasks.
•	addTask(): This function allows a user to interactively add a task to the system. It prompts the user to enter task-related information such as ID, duration, dependencies, and required skills. It checks for task ID uniqueness, validates input, and adds the task to the system.
•	setTaskDuration(): This function allows the user to set the duration of each task in the system. It iterates through the list of tasks and prompts the user to provide the duration for each task.
•	set_nth_TaskDuration(): This function allows the user to set the duration of the nth task in the system. It asks the user for the task number (n) and then updates the duration of that specific task.
•	printTaskDependencyList(): This function prints a list of tasks and their dependencies. It displays the tasks and the IDs of tasks they depend on.
•	calculateCPM(): This function calculates the Critical Path Method (CPM) for the project. It computes the earliest start and finish times for each task, as well as the latest start and finish times. It also determines the project completion time.
•	calculateBasicSchedule(): This function calculates and prints the basic schedule information for all tasks in the project, including their durations, start and finish times, slack, and dependencies.
•	printCriticalPath(): This function prints the critical path of the project, which consists of tasks with zero slack.
•	printCompletionTime(): This function prints the completion time for the entire project, including details such as task duration, required skills, slack, earliest start, and earliest finish times.
•	completionTimeWithResources(): This function calculates and prints the completion time of the project while considering resource constraints, such as resource availability and required skills.
•	completionTimeWithResourceProficiency(): This function calculates and prints the completion time of the project, taking into account resource proficiency and skills required for each task. It considers resource proficiency when calculating task durations.
Summary
This code demonstrates the functionality of your CPM-based project scheduling program. It allows users to interactively manage resources, tasks, and scheduling, and provides options for calculations and analysis.
References
Asana - Critical Path Method
GeeksforGeeks - Software Engineering Critical Path Method
