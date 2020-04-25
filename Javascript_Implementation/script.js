const CROSS_CLASS = 'cross';
const CIRCLE_CLASS = 'circle';

// Select by class
const playerElement = document.querySelector('.enter-players');
const cellElements = document.querySelectorAll('[data-cell]');
const board = document.querySelector('.board');
const winningMessageElement = document.querySelector('.winning-message');
const restartElement = document.querySelector('.restart');
const message = document.querySelector('.message');

// Select by ID
const playerForm = document.getElementById('player-details');


var success = false;
var playerCross = 0;
var playerCircle = 0;
var player = "Player";

function initialize()
{
  circleTurn = true;
  primaryDiag = 0;
  secDiag = 0;
  checkRow = [0, 0, 0];
  checkCol = [0, 0, 0];
  isWinner = false;
  moveCount = 0;
  winningMessageElement.classList.add('hide-container');
  message.innerHTML = (playerCircle + "'s turn.");
  if(status)
    playerElement.classList.add('hide-container')
  cellElements.forEach(cell => {
    document.getElementById(cell.id).textContent = '';
  });
}


/* Enter the names of the players */
playerForm.addEventListener('submit', enterName);

function enterName()
{
    if(this.player1.value == '' || this.player2.value == '')
    {
      alert("Enter the details again !");
    }
    else
    {
      playerCircle = this.player1.value;
      playerCross = this.player2.value;
      console.log(playerCircle + playerCross);
      board.classList.remove('hide-container');
      status = true;
      startGame();
    }
}

function currentPlayer()
{
  player = circleTurn ? playerCircle : playerCross;
}

function placeMark(cell, curr)
{
    cell.classList.add(curr);
    let symbol = circleTurn ? "O" : "X";
    document.getElementById(cell.id).textContent = symbol;
}

function alterMove()
{
    circleTurn = !circleTurn;
    moveCount++;
    currentPlayer();
    message.innerHTML = (player + "'s turn.");
}

function checkWinner(r, c)
{
   let val = circleTurn ? 1 : -1;
   if(r == c)
     primaryDiag += val;
   if(r + c == 2)
     secDiag += val;
   checkRow[r] += val;
   checkCol[c] += val;
   if(Math.abs(primaryDiag) == 3 || Math.abs(secDiag) == 3 || Math.abs(checkRow[r]) == 3 || Math.abs(checkCol[c]) == 3)
    isWinner = true;
}

function handleClick(e)
{
  const cell = e.target;
  const curr = circleTurn ? CIRCLE_CLASS : CROSS_CLASS;
  placeMark(cell, curr);
  checkWinner(cell.id[0], cell.id[1]);
  if(isWinner)
  {
      winningMessageElement.classList.remove('hide-container');
      cellElements.forEach(i => {
        i.removeEventListener('click', handleClick);
      });
      message.innerHTML = (player + " wins.");
      restartElement.addEventListener('click', clickRestart);
  }
  else
  if(moveCount == 8)
  {
    winningMessageElement.classList.remove('hide-container');
    message.innerHTML = "Draw";
    restartElement.addEventListener('click', clickRestart);
  }
  else
    alterMove();
}

function clickRestart()
{
  startGame();
}

function startGame()
{
  initialize();
  cellElements.forEach(cell => {
    cell.classList.remove(CROSS_CLASS);
    cell.classList.remove(CIRCLE_CLASS);
    cell.removeEventListener('click', handleClick);
    cell.addEventListener('click', handleClick, { once: true });
  });
}
