/**
* Used to sort a vector<Course> alphanumerically
* 
* @param c1 Course 1
* @param c2 Course 2
* @return bool that, if true, means c1 is ordered before c2
*/
bool alphanumericCourseSort(const Course& c1, const Course& c2) {
    return c1.courseId < c2.courseId;
}

/**
* Print all courses in alphanumeric order
* 
* @param reversed option to print in reverse order
*/
void HashTable::PrintAll(bool reversed) {
    
    // Getting all courses inside table
    vector<Course> courses;

    for (Node& node : this->nodes) {
        Node* currNode = &node;

        while (currNode != nullptr) {
            // Adds non-empty Course
            if (currNode->course.courseId != NULL_ID) {
                courses.push_back(currNode->course);
            }
            currNode = currNode->next;
        }
    }

    // Sorts the vector alphanumerically
    sort(courses.begin(), courses.end(), alphanumericCourseSort);

    // Reversing the order
    if (reversed) {
        reverse(courses.begin(), courses.end());
    }

    for (const Course& course : courses) {
        displayCourse(course);
    }
}
