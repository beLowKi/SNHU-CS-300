# SNHU-CS-300
SNHU Course repository

# Reflection Questions
- What was the problem you were solving in the projects for this course?

Projects One and Two involved choosing and implementing a data structure for a pretend LMS (learning management system) like Google Classroom or Brightspace. This included parsing a csv file of course information--getting each course's ID, title, and prerequisite courses and storing them in a Course structure. Finally, we chose between a vector, bucketed hash table, and binary search tree based on what we determined to be the most suited for the application.

- How did you approach the problem? Consider why data structures are important to understand.

I based my decision on the desired form and function of the application. I knew that insertion and searching were especially important for managing course information, so that ruled out using a vector. While random access, in C++, has a constant runtime complexity, searching for a particular course by ID isn't. Inserting into a vector also has an inconsistent run-time because of the variable number of "shifts" --effectively moving items over to make space for the insertion. Finally, I chose a hash table of a BST (binary search tree) because it's more consistent. From what I saw of the csv course file, it looked like courses were pre-sorted by ID, and I was worried that would result in a degenerate BST. Thus, by process of elimination, I chose to use a hash table.
  
- How did you overcome any roadblocks you encountered while going through the activities or project?

One of the bigger roadblocks I encoutered was handling preqrequisite courses. Each Course structure has a 'prerequisites' variable, and I had a hard time deciding what data type it should be. Originally, it was a vector<string> of each prerequisite's courseId, but that conflicted with the app's 'displayCourse' method. Displaying course information includes showing the ID and title of its prerequisite courses. Doing so with a vector<string> of courseIds would involve calling hashTable.Search for every prerequisite, and, while that would certainly have been possible, at the time, I was worried this would complicate the method's run-time complexity. The solution I chose was to make 'prerequisites' a vector<Course>. That way, their ID and title could be accessed from 'displayCourse'.

In hindsight, I probably could've kept 'prerequisites' as a vector<string> because bucketed hash tables' search function, generally, has a constant run-time complexity. Thus, it wouldn't have affected 'displayCourse' that much to include it. This also would have reduced the application's memory usage and increased its modularity, readabiliy, and debuggability. I also could've used a vector<Course*> --using pointers to directly relate Courses to their prerequisites. If I were to remake the app, I would explore both options a bit more.
  
- How has your work on this project expanded your approach to designing software and developing programs?

This project has made me realize the amount of thought that goes into choosing data structures. I'm sure many programmers, like myself, take for granted the speed and size of modern memory when we choose which data structure to use for personal or smaller projects. For this project, I had to be more deliberate about a decision which I've made casually plenty of times before, and it's made me think more about my designs.

- How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

In a previous questions I mentioned how my decision on how to deal with prerequisite courses had the unforeseen consequence of overcomplicating the application, and I think this project has showed me how often I make those kinds of decisions. It can be difficult to see how complex a program is becoming when you're the one writing it because, hopefully, you fully understand what it is you're making. What seems maintainable, readable, and adaptable to us as we're writing it may be unecessarily complicated in retrospect; i.e. nesting a vector of prerequisite Courses inside another Course. This project has affirmed that the key to maintainability, readability, and adaptability is simplicity.
