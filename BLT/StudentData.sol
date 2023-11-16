//SPDX-License-Identifier: MIT
pragma solidity ^0.8.18;
contract StudentDetails {
address public owner;
mapping (address=>student) students;
constructor() {
owner = msg.sender;
}
modifier onlyOwner{
require(msg.sender == owner);
_;
}
struct student{
address StudentId;
string name;
string course;
uint256 marks1;
uint256 marks2;
uint256 marks3;
uint256 totalMarks;
uint256 percentage;
bool isExist;
}
function register(address StudentId, string memory name, string memory course, uint256
marks1, uint256 marks2, uint256 marks3) public onlyOwner{
 require(students[StudentId].isExist == false,"Already Registered");
 uint256 totalMarks;
 uint256 percentage;
 totalMarks = marks1+marks2+marks3;
 percentage = (totalMarks/3);
 students[StudentId] =
student(StudentId,name,course,marks1,marks2,marks3,totalMarks,percentage,true);
}
function getStudentDetails(address StudentId) public view returns(address, string memory,
string memory, uint256,uint256) {
 return(
 students[StudentId].StudentId,
 students[StudentId].name,
 students[StudentId].course,
 students[StudentId].totalMarks,
 students[StudentId].percentage);
}
}