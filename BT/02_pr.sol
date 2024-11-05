// Solidity version 0.8.0 or above is recommended for added security
//SPDX-License-Identifier:UNLICENSED
pragma solidity ^0.8.0;

// Creating a contract named StudentData
contract StudentData {
    // Defining a structure to store individual student information
    struct Student {
        uint id;
        string name;
        uint age;
        string course;
    }

    // Mapping to store student information by ID
    mapping(uint => Student) private students;

    // Event to log student creation
    event StudentCreated(uint id, string name, uint age, string course);

    // Function to add a student to the contract
    function addStudent(uint _id, string memory _name, uint _age, string memory _course) public {
        // Create a new student and store it in the mapping
        students[_id] = Student(_id, _name, _age, _course);
        emit StudentCreated(_id, _name, _age, _course);
    }

    // Function to retrieve student information by ID
    function getStudent(uint _id) public view returns (uint, string memory, uint, string memory) {
        Student memory student = students[_id];
        return (student.id, student.name, student.age, student.course);
    }
}
