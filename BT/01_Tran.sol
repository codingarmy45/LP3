//SPDX-License-Identifier:UNLICENSED
pragma solidity ^0.8.0;
contract Bank{
    address public accholder;
    uint256 balance=0;

    constructor(){
        accholder=msg.sender;
    }

    function withdraw(uint256 amt) public payable{
        require(balance >= amt,"You don't have enough balance");
        require(msg.sender == accholder,"You are not the account owner.");
        payable(msg.sender).transfer(amt);
        balance -= amt;
    }

    function deposit()public payable{
        require(msg.value > 0,"Deposit amount should be greater than 0.");
        require(msg.sender == accholder,"You are not the account owner.");
        balance += msg.value;
    }

    function showBalance()public view returns(uint){
        require(msg.sender == accholder,"You are not the account owner.");
        return balance;
    }
}
