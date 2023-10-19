#include <assert.h>
#include <iostream>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
void unit_isValidMove_bishop_one() {
	Student::ChessBoard board(4, 4);
	board.createChessPiece(White, Bishop, 0, 0);
	

	assert(board.isValidMove(0, 0, 3, 3));
	assert(!board.isValidMove(0, 0, 1, 2));
	assert(!board.isValidMove(0, 0, -1, -1));
}

void unit_isValidMove_bishop_two() {
	Student::ChessBoard board(4, 4);
	board.createChessPiece(Black, Bishop, 0, 0);
	

	assert(board.isValidMove(0, 0, 3, 3));
}

void unit_isValidMove_Rook() {
	Student::ChessBoard board(4, 4);
	board.createChessPiece(White, Rook, 0, 0);
	

	assert(board.isValidMove(0, 0, 3, 0));
    assert(board.isValidMove(0, 0, 0, 3));
    assert(!board.isValidMove(0, 0, 3, 3));
	assert(!board.isValidMove(0, 0, 1, 2));
	assert(!board.isValidMove(0, 0, -1, -1));
}

void unit_isValidMove_Pawn() {
	Student::ChessBoard board(4, 4);
	board.createChessPiece(White, Pawn, 3, 0);
	

	assert(board.isValidMove(3, 0, 2, 0));
    assert(!board.isValidMove(0, 0, 1, 0));
    assert(!board.isValidMove(0, 0, 0, 1));
	assert(!board.isValidMove(0, 0, 1, 2));
	assert(!board.isValidMove(0, 0, -1, -1));
}

void part1_44_3(){
     Student::ChessBoard board(4, 4);
    
    // Setting up the board based on the configuration
    board.createChessPiece(White, Bishop, 2, 2);
    board.createChessPiece(White, Rook, 1, 0);
    board.createChessPiece(White, Pawn, 1, 1);
    board.createChessPiece(Black, Pawn, 0, 1);

    //std::cout << board.displayBoard().str() << std::endl;

    // Now, you can add assertions for the isValidMove() function based on the setup
    // Here are some examples:

    // Testing the White Bishop's moves
    assert(board.isValidMove(2, 2, 3, 3));  // Valid diagonal move
    assert(!board.isValidMove(2, 2, 2, 0));  // Invalid horizontal move

    // // Testing the White Rook's moves
    assert(board.isValidMove(1, 0, 3, 0));  // Valid vertical move
    assert(!board.isValidMove(1, 0, 1, 2));  // Invalid move due to obstruction by the White Pawn

    // // Testing the White Pawn's moves
    assert(board.isValidMove(1, 1, 0, 1));  // Valid move to capture the Black Pawn
    assert(!board.isValidMove(1, 1, 1, 2));  // Invalid horizontal move

    // // Testing the Black Pawn's moves
    assert(board.isValidMove(0, 1, 1, 1));  // Valid move to capture the White Pawn
    assert(!board.isValidMove(0, 1, 0, 0));  // Invalid horizontal mo
}

void unit_PawnPiece_Movement() {
    Student::ChessBoard board(8, 8); // Standard 8x8 board for this example

    // Testing black pawn's movement from row 1
    board.createChessPiece(Black, Pawn, 1, 3);
    assert(board.isValidMove(1, 3, 2, 3));  // Valid 1 step move
    assert(board.isValidMove(1, 3, 3, 3));  // Valid 2 step move
    assert(!board.isValidMove(1, 3, 4, 3));  // Invalid more than 2 steps move

    // Testing white pawn's movement from row n-2
    board.createChessPiece(White, Pawn, 6, 4);
    assert(board.isValidMove(6, 4, 5, 4));  // Valid 1 step move
    assert(board.isValidMove(6, 4, 4, 4));  // Valid 2 step move
    assert(!board.isValidMove(6, 4, 3, 4));  // Invalid more than 2 steps move

    // Testing pawn's diagonal consumption
    board.createChessPiece(Black, Pawn, 2, 2);
    board.createChessPiece(White, Rook, 3, 3);  // Placing an opponent piece diagonally
    assert(board.isValidMove(2, 2, 3, 3));  // Valid diagonal move to consume the rook
}

void unit_SameSpot_Movement() {
    Student::ChessBoard board(8, 8);

    board.createChessPiece(Black, Bishop, 3, 3);
    assert(!board.isValidMove(3, 3, 3, 3));  // Invalid move as it's the same spot
}

void unit_OutOfBounds_Movement() {
    Student::ChessBoard board(8, 8);

    board.createChessPiece(White, Rook, 7, 7);
    assert(!board.isValidMove(7, 7, 7, 8));  // Invalid move as it's out of bounds
}

void unit_Obstruction_Movement() {
    Student::ChessBoard board(8, 8);

    board.createChessPiece(Black, Rook, 2, 2);
    board.createChessPiece(White, Pawn, 2, 4);  // Placing a piece in the path of the rook
    assert(!board.isValidMove(2, 2, 2, 5));  // Invalid move due to obstruction
}

void unit_SameColorAtDestination_Movement() {
    Student::ChessBoard board(8, 8);

    board.createChessPiece(Black, Bishop, 3, 3);
    board.createChessPiece(Black, Pawn, 5, 5);  // Placing a black pawn in the path of the black bishop
    assert(!board.isValidMove(3, 3, 5, 5));  // Invalid move as destination has a piece of the same color
}

void part1_44_4(){
    Student::ChessBoard board(4, 4);
    
    // Setting up the board based on the configuration
    board.createChessPiece(White, Rook, 3, 2);
    board.createChessPiece(Black, Bishop, 3, 0);
    board.createChessPiece(Black, Rook, 2, 2);
    board.createChessPiece(Black, Bishop, 1, 1);

    // std::cout << board.displayBoard().str() << std::endl;

    assert(board.isValidMove(1, 1, 2, 0));  // Valid move to capture the White Pawn
    assert(!board.isValidMove(1, 1, 2, 2));  // Invalid horizontal mo
    assert(!board.isValidMove(1, 1, 2, 1));
    assert(!board.isValidMove(3, 2, 0, 2));
    assert(board.isValidMove(3, 2, 3, 3));
}

void overwrite_test() {
    Student::ChessBoard board(8, 8);

    board.createChessPiece(Black, Rook, 2, 2);
    board.createChessPiece(Black, Pawn, 2, 4);
    board.createChessPiece(White, Pawn, 2, 4);  // Placing a piece in the path of the rook
    std::cout << board.displayBoard().str() << std::endl;
    assert(!board.isValidMove(2, 2, 2, 5));  // Invalid move due to obstruction
}

void unit_isValidScan_Comprehensive() {
    Student::ChessBoard board(8, 8);
    
    // Setting up the board based on the configuration
    board.createChessPiece(Black, Bishop, 2, 7);
    board.createChessPiece(White, Pawn, 0, 5);
    board.createChessPiece(Black, Pawn, 7, 6);
    board.createChessPiece(Black, Rook, 2, 4);
    board.createChessPiece(White, Rook, 2, 1);
    board.createChessPiece(Black, Bishop, 2, 7);
    board.createChessPiece(Black, Rook, 5, 3);
    board.createChessPiece(Black, Bishop, 2, 6);
    board.createChessPiece(White, Rook, 5, 5);
    board.createChessPiece(White, Rook, 2, 2);
    board.createChessPiece(Black, Pawn, 1, 5);
    board.createChessPiece(Black, Bishop, 2, 7);
    board.createChessPiece(Black, Bishop, 0, 1);
    board.createChessPiece(Black, Rook, 0, 3);
    board.createChessPiece(Black, Bishop, 6, 1);
    board.createChessPiece(Black, Rook, 7, 0);

    std::cout << board.displayBoard().str() << std::endl;

    // Testing moves for Black Bishop at (2, 7)
    assert(board.isValidMove(2, 7, 0, 5));  // Blocked by White Pawn
    assert(board.isValidMove(2, 7, 4, 5));   // Valid diagonal move

    // Testing moves for White Pawn at (0, 5)
    assert(!board.isValidMove(0, 5, 1, 5));   // Valid forward move
    assert(!board.isValidMove(0, 5, 0, 6));  // Invalid horizontal move

    // Testing moves for Black Rook at (2, 4)
    assert(!board.isValidMove(2, 4, 2, 6));   // Valid horizontal move
    assert(board.isValidMove(2, 4, 0, 4));  // Blocked by Black Bishop

    // ... Continue testing moves for other pieces ...

    // Testing moves for Black Rook at (7, 0)
    assert(board.isValidMove(7, 0, 5, 0));   // Valid vertical move
    assert(board.isValidMove(7, 0, 7, 2));  // Blocked by Black Pawn

    // ... Add more assertions based on other possible moves and scenarios ...
}

void test_part1_4x4_1() {
    // Corresponding code
    Student::ChessBoard sBoard(4, 4);
    
    // Setting up the board based on the configuration
    sBoard.createChessPiece(White, Rook, 3, 2);
    sBoard.createChessPiece(Black, Bishop, 1, 3);
    sBoard.createChessPiece(Black, Rook, 1, 1);
    sBoard.createChessPiece(White, Rook, 2, 3);

    // Calls isValidMove() from every position to
    // every other position on the chess board for
    // all pieces and checks the results.
    for (int fromRow = 0; fromRow < 4; ++fromRow) {
        for (int fromCol = 0; fromCol < 4; ++fromCol) {
            for (int toRow = 0; toRow < 4; ++toRow) {
                for (int toCol = 0; toCol < 4; ++toCol) {
                    bool result = sBoard.isValidMove(fromRow, fromCol, toRow, toCol);
                    
                    // Here, you can add assertions or checks based on your expectations.
                    // For example:
                    if (fromRow == 3 && fromCol == 2 && toRow == 3 && toCol == 0) {
                        assert(result == true); // Expecting the move to be valid for the White Rook
                    }
                    // ... Add more assertions based on other scenarios and expectations.
                }
            }
        }
    }

    return;
}


int main()
{
    unit_isValidMove_bishop_one();
    unit_isValidMove_Rook();
    unit_isValidMove_Pawn();
    unit_PawnPiece_Movement();
    part1_44_3();
    unit_SameSpot_Movement();
    unit_OutOfBounds_Movement();
    unit_Obstruction_Movement();
    unit_SameColorAtDestination_Movement();
    part1_44_4();
    overwrite_test();
    unit_isValidScan_Comprehensive();
    test_part1_4x4_1();
    return EXIT_SUCCESS;
}