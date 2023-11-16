// SPDX-License-Identifier: MIT
pragma solidity ^0.8.18;
contract EtherWallet {
address payable public owner;
constructor() {
owner = payable(msg.sender);
}
function Withdraw(uint _amount) public {
 require(msg.sender == owner && address(this).balance > _amount);
 payable(msg.sender).transfer(_amount);
}
function getBalance() external view returns(uint) {
 return address(this).balance;
}
receive() external payable {}
}