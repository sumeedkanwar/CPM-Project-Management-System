//Sumeed_Jawad_Kanwar_22i-2651_Assignment2
#include <iostream>

using namespace std;
//Menu function
void Menu()
{
	cout << "1. Add Resources" << endl;
	cout << "2. Add Task" << endl;
	cout << "3. Set Task Duration" << endl;
	cout << "4. Set nth Task Duration" << endl;
	cout << "5. Print Task Dependency List" << endl;
	cout << "6. Calculate Basic Schedule" << endl;
	cout << "7. Print Critical Path" << endl;
	cout << "8. Completion Time with Resources" << endl;
	cout << "9. Completion Time with Resource Proficiency" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter your choice: ";
}
//Skill class
class Skill
{
public:
	int id;
	float proficiency;
	//Constructors
	Skill()
	{
		this->id = 0;
		this->proficiency = 0.0;
	}
	Skill(int id, float proficiency)
	{
		this->id = id;
		this->proficiency = proficiency;
	}
	//Getters
	int getId()
	{
		return this->id;
	}
	float getProficiency()
	{
		return this->proficiency;
	}
	//Setters
	void setId(int id)
	{
		this->id = id;
	}
	void setProficiency(float proficiency)
	{
		this->proficiency = proficiency;
	}
};
//SkillNode class
class SkillNode
{
public:
	Skill* skill;
	SkillNode* next;
	//Constructors
	SkillNode()
	{
		this->skill = NULL;
		this->next = NULL;
	}
	SkillNode(Skill* skill)
	{
		this->skill = skill;
		this->next = NULL;
	}
	//Getters
	Skill* getSkill()
	{
		return this->skill;
	}
	SkillNode* getNext()
	{
		return this->next;
	}
	//Setters
	void setSkill(Skill* skill)
	{
		this->skill = skill;
	}
	void setNext(SkillNode* next)
	{
		this->next = next;
	}
};
//Resource class
class Resource
{
public:
	int id;
	bool availability = true;
	SkillNode* skills;
	Resource* next;
	//Constructors
	Resource()
	{
		this->id = 0;
		this->availability = true;
		this->skills = NULL;
		this->next = NULL;
	}
	Resource(int id)
	{
		this->id = id;
		this->availability = true;
		this->skills = NULL;
		this->next = NULL;
	}
	Resource(int id, bool availability)
	{
		this->id = id;
		this->availability = availability;
		this->skills = NULL;
		this->next = NULL;
	}
	//Getters
	int getId()
	{
		return this->id;
	}
	bool getAvailability()
	{
		return this->availability;
	}
	SkillNode* getSkills()
	{
		return this->skills;
	}
	Resource* getNext()
	{
		return this->next;
	}
	//Setters
	void setId(int id)
	{
		this->id = id;
	}
	void setAvailability(bool availability)
	{
		this->availability = availability;
	}
	void setSkills(SkillNode* skills)
	{
		if (this->skills == NULL)
		{
			this->skills = skills;
		}
		else
		{
			SkillNode* current = this->skills;
			while (current->getNext() != NULL)
			{
				current = current->getNext();
			}
			current->setNext(skills);
		}
	}
	void setNext(Resource* next)
	{
		this->next = next;
	}
};
//Task class
class Task
{
public:
	int id;
	int duration;
	int earliestStart;
	int latestStart;
	int slack;
	int earliestFinish;
	int latestFinish;
	Skill* requiredSkill;
	Task* allDependencies;
	Task* dependencies;
	Task* successor;
	Task* allSuccessors;
	int requiredResourceId;
	//Constructors
	Task()
	{
		this->id = 0;
		this->duration = 0;
		this->dependencies = NULL;
		this->successor = NULL;
		this->allDependencies = NULL;
		this->allSuccessors = NULL;
		this->requiredSkill = NULL;
		this->earliestStart = 0;
		this->latestStart = 0;
		this->slack = 0;
		this->earliestFinish = 0;
		this->latestFinish = 0;
		this->requiredResourceId = 0;
	}
	Task(int id, int duration)
	{
		this->id = id;
		this->duration = duration;
		this->dependencies = NULL;
		this->successor = NULL;
		this->allDependencies = NULL;
		this->allSuccessors = NULL;
		this->requiredSkill = NULL;
		this->earliestStart = 0;
		this->latestStart = 0;
		this->slack = 0;
		this->earliestFinish = 0;
		this->latestFinish = 0;
		this->requiredResourceId = 0;
	}
	//Getters
	int getId()
	{
		return this->id;
	}
	int getDuration()
	{
		return this->duration;
	}
	Task* getDependencies()
	{
		return this->dependencies;
	}
	Task* getSuccessor()
	{
		return this->successor;
	}
	int getEarliestStart()
	{
		return this->earliestStart;
	}
	int getLatestStart()
	{
		return this->latestStart;
	}
	int getSlack()
	{
		return this->slack;
	}
	int getEarliestFinish()
	{
		return this->earliestFinish;
	}
	int getLatestFinish()
	{
		return this->latestFinish;
	}
	Skill* getRequiredSkill()
	{
		return this->requiredSkill;
	}
	int getRequiredSkillId()
	{
		if (this->requiredSkill == NULL)
		{
			return 0;
		}
		else
		{
			return this->requiredSkill->getId();
		}
	}
	int getRequiredResourceId()
	{
		return this->requiredResourceId;
	}
	//Setters
	void setId(int id)
	{
		this->id = id;
	}
	void setDuration(int duration)
	{
		this->duration = duration;
	}
	void setDependencies(Task* dependencies)
	{
		if (this->dependencies == NULL)
		{
			this->dependencies = dependencies;
		}
		else
		{
			Task* current = this->dependencies;
			while (current->allDependencies != NULL)
			{
				current = current->allDependencies;
			}
			current->allDependencies = dependencies;
		}
	}
	void setSuccessor(Task* successor)
	{
		if (this->successor == NULL)
		{
			this->successor = successor;
		}
		else
		{
			Task* current = this->successor;
			while (current->allSuccessors != NULL)
			{
				current = current->allSuccessors;
			}
			current->allSuccessors = successor;
		}
	}
	void setEarliestStart(int earliestStart)
	{
		this->earliestStart = earliestStart;
	}
	void setLatestStart(int latestStart)
	{
		this->latestStart = latestStart;
	}
	void setSlack(int slack)
	{
		this->slack = slack;
	}
	void setEarliestFinish(int earliestFinish)
	{
		this->earliestFinish = earliestFinish;
	}
	void setLatestFinish(int latestFinish)
	{
		this->latestFinish = latestFinish;
	}
	void setRequiredSkill(Skill* requiredSkill)
	{
		this->requiredSkill = requiredSkill;
	}
	void setRequiredSkillId(int id)
	{
		if (this->requiredSkill == NULL)
		{
			this->requiredSkill = new Skill(id, 0);
		}
		else
		{
			this->requiredSkill->setId(id);
		}
	}
	void setRequiredResourceId(int id)
	{
		this->requiredResourceId = id;
	}
};
//TaskNode class
class TaskNode
{
public:
	Task* task;
	TaskNode* next;
	TaskNode* prev;
	//Constructors
	TaskNode()
	{
		this->task = NULL;
		this->next = NULL;
		this->prev = NULL;
	}
	TaskNode(Task* task)
	{
		this->task = task;
		this->next = NULL;
		this->prev = NULL;
	}
	//Getters
	Task* getTask()
	{
		return this->task;
	}
	TaskNode* getNext()
	{
		return this->next;
	}
	TaskNode* getPrev()
	{
		return this->prev;
	}
	//Setters
	void setTask(Task* task)
	{
		this->task = task;
	}
	void setNext(TaskNode* next)
	{
		this->next = next;
	}
	void setPrev(TaskNode* prev)
	{
		this->prev = prev;
	}
};
//TaskList class
class TaskList
{
public:
	TaskNode* head;
	TaskNode* tail;
	//Constructors
	TaskList()
	{
		this->head = NULL;
		this->tail = NULL;
	}
	//Getters
	TaskNode* getHead()
	{
		return this->head;
	}
	TaskNode* getTail()
	{
		return this->tail;
	}
	//Setters
	void setHead(TaskNode* head)
	{
		this->head = head;
	}
	void setTail(TaskNode* tail)
	{
		this->tail = tail;
	}
	//Methods
	void addTask(Task* task)
	{
		TaskNode* newNode = new TaskNode(task);
		if (this->head == NULL)
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			this->tail->setNext(newNode);
			newNode->setPrev(this->tail);
			this->tail = newNode;
		}
	}
};
//Project class
class Project
{
public:
	TaskList* tasks;
	Resource* resources;
	int startTime = 0;
	int endTime = 0;
	//Constructors
	Project()
	{
		this->tasks = new TaskList();
		this->resources = NULL;
	}
	//Getters
	TaskList* getTasks()
	{
		return this->tasks;
	}
	Resource* getResources()
	{
		return this->resources;
	}
	//Setters
	void setTasks(TaskList* tasks)
	{
		this->tasks = tasks;
	}
	void setResources(Resource* resources)
	{
		this->resources = resources;
	}
	//Functions
	void addResource(Resource* resource)
	{
		if (this->resources == NULL)
		{
			this->resources = resource;
		}
		else
		{
			Resource* current = this->resources;
			while (current->getNext() != NULL)
			{
				current = current->getNext();
			}
			current->setNext(resource);
		}
	}
	//Add resource function
	void addResource()
	{
		bool check = false;
		Resource* resource = new Resource();
		do
		{
			cout << "Enter resource ID: ";
			cin >> resource->id;
			Resource* current = this->resources;
			check = true; // Assume the resource ID is unique until proven otherwise

			while (current != NULL)
			{
				if (current->getId() == resource->id)
				{
					cout << "Resource ID already exists. Please enter a different ID." << endl;
					check = false; // Resource ID is not unique; set check to false
					break; // No need to continue checking
				}
				current = current->getNext();
			}
		} while (check == false);
		cout << "Enter number of skills: ";
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			Skill* skill = new Skill();
			// Check if the skill ID is unique
			do
			{
				cout << "Enter skill ID: ";
				cin >> skill->id;
				SkillNode* skillNode = resource->getSkills();
				check = true;
				Resource* current = this->resources;
				while (current != NULL)
				{
					skillNode = current->getSkills();
					while (skillNode != NULL)
					{
						Skill* skill1 = skillNode->getSkill();
						if (skill1->getId() == skill->id)
						{
							cout << "Skill ID already exists. Please enter a different ID." << endl;
							check = false;
							break;
						}
						skillNode = skillNode->getNext();
					}
					current = current->getNext();
				}


			} while (check == false);
			cout << "Enter proficiency: ";
			cin >> skill->proficiency;
			SkillNode* skillNode = new SkillNode(skill);
			resource->setSkills(skillNode);
		}
		this->addResource(resource);
	}
	void addTask(Task* task)
	{
		this->tasks->addTask(task);
	}
	//Add task function
	void addTask()
	{
		// Check if any resources exist
		if (this->resources == NULL)
		{
			cout << "No resources found. Please add resources first." << endl;
			return;
		}
		bool check = false;
		Task* task = new Task();
		do
		{
			cout << "Enter task ID: ";
			cin >> task->id;
			TaskNode* current = this->tasks->getHead();
			check = true; // Assume the task ID is unique until proven otherwise

			while (current != NULL)
			{
				Task* task1 = current->getTask();
				if (task1->getId() == task->id)
				{
					cout << "Task ID already exists. Please enter a different ID." << endl;
					check = false; // Task ID is not unique; set check to false
					break; // No need to continue checking
				}
				current = current->getNext();
			}
		} while (check == false);
		do
		{
			cout << "Enter task duration: ";
			cin >> task->duration;
			if (task->duration <= 0)
			{
				cout << "Duration must be greater than 0." << endl;
			}
		} while (task->duration <= 0);
		do
		{
			cout << "Start time: ";
			cin >> task->earliestStart;
			if (task->earliestStart < 0)
			{
				cout << "Start time must be greater than or equal to 0." << endl;
			}
		} while (task->earliestStart < 0);
		cout << "Enter task dependencies (-1 if no dependency): ";
		int dependency;
		cin >> dependency;

		while (dependency != -1)
		{
			Task* dependencyTask = nullptr;

			// Find an existing task with the given ID
			TaskNode* current = this->tasks->getHead();
			while (current != nullptr)
			{
				Task* task1 = current->getTask();
				if (task1->getId() == dependency)
				{
					dependencyTask = task1;
					break;
				}
				current = current->getNext();
			}

			if (dependencyTask == nullptr)
			{
				// The task with the given ID does not exist
				cout << "Task with ID " << dependency << " does not exist." << endl;
			}
			else
			{
				// Add the existing task as a dependency
				task->setDependencies(dependencyTask);
				dependencyTask->setSuccessor(task);
			}

			cout << "Enter task dependencies (-1 if no more dependency): ";
			cin >> dependency;
		}

		int requiredSkill;
		Resource* current = this->resources;
		do
		{
			cout << "Enter required skill ID: ";
			cin >> requiredSkill;
			check = false; // Assume the skill ID is not found until proven otherwise

			while (current != NULL)
			{
				SkillNode* skillNode = current->getSkills();
				while (skillNode != NULL)
				{
					Skill* skill = skillNode->getSkill();
					if (skill->getId() == requiredSkill)
					{
						task->setRequiredSkill(skill);
						task->setRequiredResourceId(current->getId());
						check = true; // Skill ID is found; set check to true
						break; // No need to continue checking
					}
					skillNode = skillNode->getNext();
				}
				current = current->getNext();
			}
			if (check == false)
			{
				cout << "Skill ID not found. Please enter a different ID." << endl;
			}
		} while (check == false);

		this->tasks->addTask(task);

	}
	//Set task duration function
	void setTaskDuration()
	{
		// Check if any tasks exist
		if (this->tasks->getHead() == NULL)
		{
			cout << "No tasks found. Please add tasks first." << endl;
			return;
		}
		TaskNode* current = this->tasks->getHead();
		while (current != NULL)
		{
			Task* task = current->getTask();
			int duration;
			do
			{
				cout << "Enter duration for task " << task->getId() << ": ";
				cin >> duration;
			} while (duration <= 0);
			task->setDuration(duration);
			current = current->getNext();
		}
	}
	//Set nth task duration function
	void set_nth_TaskDuration()
	{
		// Check if any tasks exist
		if (this->tasks->getHead() == NULL)
		{
			cout << "No tasks found. Please add tasks first." << endl;
			return;
		}
		TaskNode* current = this->tasks->getHead();
		int n;
		do
		{
			cout << "Enter task number: ";
			cin >> n;
		} while (n <= 0);
		for (int i = 1; i < n; i++)
		{
			if (current == NULL)
			{
				cout << "Task number " << n << " does not exist." << endl;
				return;
			}
			current = current->getNext();
		}
		Task* task = current->getTask();
		int duration;
		do
		{
			cout << "Enter duration for task " << task->getId() << ": ";
			cin >> duration;
		} while (duration <= 0);
		task->setDuration(duration);
	}
	//Print task dependency list function
	void printTaskDependencyList()
	{
		if (this->tasks->getHead() == NULL)
		{
			cout << "No tasks found. Please add tasks first." << endl;
			return;
		}
		TaskNode* current = this->tasks->getHead();
		while (current != NULL)
		{
			Task* task = current->getTask();
			cout << "Task " << task->getId() << " depends on: ";
			Task* dependencies = task->getDependencies();
			if (dependencies != NULL)
			{
				while (dependencies != NULL)
				{
					cout << dependencies->getId();
					dependencies = dependencies->allDependencies;

					if (dependencies != NULL)
					{
						cout << ", "; // Separate multiple dependencies with a comma and space
					}
				}
			}
			else
			{
				cout << "None";
			}
			cout << endl;
			current = current->getNext();
		}
	}
	//Calculate CPM function
	bool calculateCPM()
	{
		// Check if any tasks exist
		if (this->tasks->getHead() == NULL)
		{
			cout << "No tasks found. Please add tasks first." << endl;
			return false;
		}
		TaskNode* current = this->tasks->getHead();
		int time = 0; // Initialize time to project start time
		//Forward pass
		while (current != NULL)
		{
			Task* task = current->getTask();
			Task* dependencies = task->getDependencies();

			if (dependencies != NULL)
			{
				while (dependencies != NULL)
				{
					if (dependencies->getEarliestFinish() > task->getEarliestStart())
					{
						task->setEarliestStart(dependencies->getEarliestFinish());
					}
					dependencies = dependencies->allDependencies;
				}
			}
			else
			{
				task->setEarliestStart(0); // Initialize earliest start for tasks with no dependencies
			}

			task->setEarliestFinish(task->getEarliestStart() + task->getDuration());

			if (time < task->getEarliestFinish())
			{
				time = task->getEarliestFinish();
			}

			current = current->getNext();
		}
		endTime = time;
		//Backward pass
		current = this->tasks->getTail();
		while (current != NULL)
		{
			Task* task = current->getTask();
			Task* dependents = task->getSuccessor();

			if (dependents != NULL)
			{
				int latestFinish = 100000;
				while (dependents != NULL)
				{
					if (latestFinish > dependents->getLatestStart())
					{
						latestFinish = dependents->getLatestStart();
					}
					dependents = dependents->allSuccessors;
				}
				task->setLatestFinish(latestFinish);
				task->setLatestStart(latestFinish - task->getDuration());
			}
			else
			{
				task->setLatestFinish(time);
				task->setLatestStart(time - task->getDuration());
			}
			task->setSlack(task->getLatestFinish() - task->getEarliestFinish());

			current = current->getPrev();
		}
		return true;
	}
	//Calculate basic schedule function
	void calculateBasicSchedule()
	{
		// Check if CPM has been calculated
		if (!calculateCPM())
		{
			return;
		}
		TaskNode* current = this->tasks->getHead();

		// Print column headers
		cout << "ID\tDuration\tES\tEF\tSlack\tLS\tLF\tDependencies" << endl;

		while (current != NULL)
		{
			Task* task = current->getTask();

			cout << task->getId() << "\t"
				<< task->getDuration() << "\t\t"
				<< task->getEarliestStart() << "\t"
				<< task->getEarliestFinish() << "\t"
				<< task->getSlack() << "\t"
				<< task->getLatestStart() << "\t"
				<< task->getLatestFinish() << "\t\t";

			Task* dependencies = task->getDependencies();
			if (dependencies != NULL)
			{
				while (dependencies != NULL)
				{
					cout << dependencies->getId();
					dependencies = dependencies->allDependencies;

					if (dependencies != NULL)
					{
						cout << ", "; // Separate multiple dependencies with a comma and space
					}
				}
			}
			else
			{
				cout << "None";
			}

			cout << endl;
			current = current->getNext();
		}
		// Print project completion time
		cout << "Project Completion Time: " << endTime << endl;
	}
	//Print critical path function
	void printCriticalPath()
	{
		// Check if CPM has been calculated
		if (calculateCPM() == false)
		{
			return;
		}
		// Print critical path
		TaskNode* current1 = this->tasks->getHead();
		cout << "Critical Path: ";
		while (current1 != NULL)
		{
			Task* task = current1->getTask();
			if (task->getSlack() == 0)
			{
				cout << task->getId() << " ";
			}
			current1 = current1->getNext();
		}
		cout << endl;
	}
	//Print completion time function
	void printCompletionTime()
	{
		cout << "Time to finish the project: " << endTime << endl;

		//Print column headers
		cout << "ID\tDuration\tSkill ID\tSlack\tStart\tFinish" << endl;

		TaskNode* current = this->tasks->getHead();
		while (current != NULL)
		{
			Task* task = current->getTask();
			cout << task->getId() << "\t"
				<< task->getDuration() << "\t\t"
				<< task->getRequiredSkillId() << "\t\t"
				<< task->getSlack() << "\t"
				<< task->getLatestStart() << "\t"
				<< task->getLatestFinish() << endl;
			current = current->getNext();
		}
	}
	//Completion time with resources function
	void completionTimeWithResources()
	{
		//Check if any resources exist
		if (this->tasks->getHead() == NULL)
		{
			cout << "No tasks found. Please add tasks first." << endl;
			return;
		}
		int time = 0;
		//Forward pass
		TaskNode* current = this->tasks->getHead();
		while (current != NULL)
		{
			Task* task = current->getTask();
			if (current->getNext() == NULL)
			{
				task->setLatestStart(time);
				time += task->getDuration();
				task->setLatestFinish(time);
				break;
			}
			else
			{
				Task* task1 = current->getNext()->getTask();
				//Check if the tasks have the same required skill
				if (task->getRequiredSkillId() == task1->getRequiredSkillId())
				{
					//Check if the tasks have the same required resource
					if (task->getLatestStart() == task1->getLatestStart())
					{
						//Check if the tasks have the same slack
						if (task->getSlack() == task1->getSlack())
						{
							//Check if the tasks have the same duration
							if (task->getDuration() < task1->getDuration())
							{
								task->setLatestStart(time);
								time += task->getDuration();
								task->setLatestFinish(time);
								task1->setLatestStart(time);
								time += task1->getDuration();
								task1->setLatestFinish(time);
							}
							else
							{
								task1->setLatestStart(time);
								time += task1->getDuration();
								task1->setLatestFinish(time);
								task->setLatestStart(time);
								time += task->getDuration();
								task->setLatestFinish(time);
							}
						}
						else if (task->getSlack() < task1->getSlack())
						{
							task->setLatestStart(time);
							time += task->getDuration();
							task->setLatestFinish(time);
							task1->setLatestStart(time);
							time += task1->getDuration();
							task1->setLatestFinish(time);
						}
						else
						{
							task1->setLatestStart(time);
							time += task1->getDuration();
							task1->setLatestFinish(time);
							task->setLatestStart(time);
							time += task->getDuration();
							task->setLatestFinish(time);
						}
					}
					else if (task->getLatestStart() < task1->getLatestStart())
					{
						task->setLatestStart(time);
						time += task->getDuration();
						task->setLatestFinish(time);
						task1->setLatestStart(time);
						time += task1->getDuration();
						task1->setLatestFinish(time);
					}
					else
					{
						task1->setLatestStart(time);
						time += task1->getDuration();
						task1->setLatestFinish(time);
						task->setLatestStart(time);
						time += task->getDuration();
						task->setLatestFinish(time);
					}
				}
				else
				{
					if (task->getRequiredResourceId() == task1->getRequiredResourceId())
					{
						task->setLatestStart(time);
						time += task->getDuration();
						task->setLatestFinish(time);
						task1->setLatestStart(time);
						time += task1->getDuration();
						task1->setLatestFinish(time);
					}
					else
					{
						task->setLatestStart(time);
						time += task->getDuration();
						task->setLatestFinish(time);
						task1->setLatestStart(time);
						time += task1->getDuration();
						task1->setLatestFinish(time);
					}
				}
			}
			current = current->getNext()->getNext();
		}
		endTime = time;
		//Print project completion time
		printCompletionTime();
	}
	//Completion time with resource proficiency function
	void completionTimeWithResourceProficiency()
	{
		// Check if any resources exist
		if (this->tasks->getHead() == NULL)
		{
			cout << "No tasks found. Please add tasks first." << endl;
			return;
		}
		//Forward pass
		int time = 0;
		float proficiency = 0.0;
		TaskNode* current = this->tasks->getHead();
		Resource* currentResource = this->resources;
		while (current != NULL)
		{
			Task* task = current->getTask();
			//Check if the task is the last task
			if (current->getNext() == NULL)
			{
				//Check if the task has a required skill
				bool check = false;
				while (currentResource != NULL && check == false)
				{
					//Check if the resource has the required skill
					SkillNode* skill = currentResource->getSkills();
					while (skill != NULL && check == false)
					{
						//Check if the skill is the required skill
						if (skill->getSkill()->getId() == task->getRequiredSkillId())
						{
							proficiency = skill->getSkill()->getProficiency();
							check = true;
							break;
						}
						skill = skill->getNext();
					}
					currentResource = currentResource->getNext();
				}
				task->setLatestStart(time);
				time += (task->getDuration() / proficiency);
				task->setLatestFinish(time);
				break;
			}
			else
			{
				Task* task1 = current->getNext()->getTask();
				//Check if the tasks have the same required skill
				if (task->getRequiredSkillId() == task1->getRequiredSkillId())
				{
					//Check if the tasks have the same required resource
					bool check = false;
					while (currentResource != NULL && check == false)
					{
						//Check if the resource has the required skill
						SkillNode* skill = currentResource->getSkills();
						while (skill != NULL && check == false)
						{
							//Check if the skill is the required skill
							if (skill->getSkill()->getId() == task->getRequiredSkillId())
							{
								proficiency = skill->getSkill()->getProficiency();
								check = true;
								break;
							}
							skill = skill->getNext();
						}
						currentResource = currentResource->getNext();
					}
					//Check if the tasks have the same slack
					if (task->getLatestStart() == task1->getLatestStart())
					{
						//Check if the tasks have the same slack
						if (task->getSlack() == task1->getSlack())
						{
							//Check if the tasks have the same duration
							if (task->getDuration() < task1->getDuration())
							{
								task->setLatestStart(time);
								time += (task->getDuration() / proficiency);
								task->setLatestFinish(time);
								task1->setLatestStart(time);
								time += (task1->getDuration() / proficiency);
								task1->setLatestFinish(time);
							}
							else
							{
								task1->setLatestStart(time);
								time += (task1->getDuration() / proficiency);
								task1->setLatestFinish(time);
								task->setLatestStart(time);
								time += (task->getDuration() / proficiency);
								task->setLatestFinish(time);
							}
						}
						else if (task->getSlack() < task1->getSlack())
						{
							task->setLatestStart(time);
							time += (task->getDuration() / proficiency);
							task->setLatestFinish(time);
							task1->setLatestStart(time);
							time += (task1->getDuration() / proficiency);
							task1->setLatestFinish(time);
						}
						else
						{
							task1->setLatestStart(time);
							time += (task1->getDuration() / proficiency);
							task1->setLatestFinish(time);
							task->setLatestStart(time);
							time += (task->getDuration() / proficiency);
							task->setLatestFinish(time);
						}
					}
					else if (task->getLatestStart() < task1->getLatestStart())
					{
						task->setLatestStart(time);
						time += (task->getDuration() / proficiency);
						task->setLatestFinish(time);
						task1->setLatestStart(time);
						time += (task1->getDuration() / proficiency);
						task1->setLatestFinish(time);
					}
					else
					{
						task1->setLatestStart(time);
						time += (task1->getDuration() / proficiency);
						task1->setLatestFinish(time);
						task->setLatestStart(time);
						time += (task->getDuration() / proficiency);
						task->setLatestFinish(time);
					}
				}
				else
				{
					//Check if the tasks have the same required resource
					if (task->getRequiredResourceId() == task1->getRequiredResourceId())
					{
						//Check if the tasks have the same slack
						bool check = false;
						while (currentResource != NULL && check == false)
						{
							SkillNode* skill = currentResource->getSkills();
							while (skill != NULL && check == false)
							{
								//Check if the skill is the required skill
								if (skill->getSkill()->getId() == task->getRequiredSkillId())
								{
									proficiency = skill->getSkill()->getProficiency();
									check = true;
									break;
								}
								skill = skill->getNext();
							}
							currentResource = currentResource->getNext();
						}
						task->setLatestStart(time);
						task->setLatestFinish((task->getDuration() / proficiency) + time);
						time += (task->getDuration() / proficiency);
						currentResource = this->resources;
						check = false;
						while (currentResource != NULL && check == false)
						{
							SkillNode* skill = currentResource->getSkills();
							while (skill != NULL && check == false)
							{
								if (skill->getSkill()->getId() == task1->getRequiredSkillId())
								{
									proficiency = skill->getSkill()->getProficiency();
									check = true;
									break;
								}
								skill = skill->getNext();
							}
							currentResource = currentResource->getNext();
						}
						task1->setLatestStart(time);
						task1->setLatestFinish((task1->getDuration() / proficiency) + time);
						time += (task1->getDuration() / proficiency);
					}
					else
					{
						bool check = false;
						while (currentResource != NULL && check == false)
						{
							SkillNode* skill = currentResource->getSkills();
							while (skill != NULL && check == false)
							{
								if (skill->getSkill()->getId() == task->getRequiredSkillId())
								{
									proficiency = skill->getSkill()->getProficiency();
									check = true;
									break;
								}
								skill = skill->getNext();
							}
							currentResource = currentResource->getNext();
						}
						task->setLatestStart(time);
						task->setLatestFinish((task->getDuration() / proficiency) + time);
						currentResource = this->resources;
						check = false;
						while (currentResource != NULL && check == false)
						{
							SkillNode* skill = currentResource->getSkills();
							while (skill != NULL && check == false)
							{
								if (skill->getSkill()->getId() == task1->getRequiredSkillId())
								{
									proficiency = skill->getSkill()->getProficiency();
									check = true;
									break;
								}
								skill = skill->getNext();
							}
							currentResource = currentResource->getNext();
						}
						task1->setLatestStart(time);
						task1->setLatestFinish((task1->getDuration() / proficiency) + time);

						if (task->getLatestFinish() > task1->getLatestFinish())
						{
							time += (task->getDuration() / proficiency);
						}
						else
						{
							time += (task1->getDuration() / proficiency);
						}
					}
				}
			}
			current = current->getNext()->getNext();
		}
		endTime = time;
		//Print project completion time
		printCompletionTime();
	}
};