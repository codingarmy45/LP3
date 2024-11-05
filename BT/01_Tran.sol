// Solidity program to retrieve address and balance of owner
pragma solidity ^0.6.8;

// Creating a contract
contract MyContract {
    // Private state variable to store the owner's address
    address payable private owner;

    // Defining a constructor to set the owner as the address that deploys the contract
    constructor() public {
        owner = msg.sender;
    }

    // Function to get the address of the owner
    function getOwner() public view returns (address) {
        return owner;
    }

    // Function to return the current balance of the owner's address
    function getBalance() public view returns (uint256) {
        return owner.balance;
    }
}
