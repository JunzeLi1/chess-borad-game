/*ChessBoard.cc*/
#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;

/*ChessBoard::ChessBoard(int numRow, int numCol){
    numRows = numRow;
    numCols = numCol;
    std::vector<std::vector<ChessPiece *>> board(numRow, 
                std::vector<ChessPiece *>(numCol, nullptr));
}*/

ChessBoard::ChessBoard(int numRow, int numCol) 
    : numRows(numRow), numCols(numCol), board(numRow, std::vector<ChessPiece *>(numCol, nullptr)) {}

ChessBoard::~ChessBoard() {
    for (auto &row : board) {
        for (auto &piece : row) {
            delete piece;
            piece = nullptr;
        }
    }
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn){
    if (board.at(startRow).at(startColumn) != nullptr) {
        delete board.at(startRow).at(startColumn);
        board.at(startRow).at(startColumn) = nullptr;
    }

    switch(ty){
        case(Pawn):
            board.at(startRow).at(startColumn) = new PawnPiece(*this, col, startRow, startColumn);
            break;

        case(Rook):
            board.at(startRow).at(startColumn) = new RookPiece(*this, col, startRow, startColumn);
            break;

        case(Bishop):
            board.at(startRow).at(startColumn) = new BishopPiece(*this, col, startRow, startColumn);
            break;

        case(King):
            board.at(startRow).at(startColumn) = new KingPiece(*this, col, startRow, startColumn);
            break;

        default:
            break;
    }
}

void ChessBoard::switchTurn() {
    if (turn == White) {
        turn = Black;
    } else {
        turn = White;
    }
}


bool ChessBoard::isPathClear(int fromRow, int fromColumn, int toRow, int toColumn){
    int row_path = toRow - fromRow;
    int col_path = toColumn - fromColumn;
    int row_dir = 0;
    int col_dir = 0;
    if(row_path > 0){
        row_dir = 1;
    }
    else if(row_path < 0){
        row_dir = -1;
    }
    
    if(col_path > 0){
        col_dir = 1;
    }
    else if(col_path < 0){
        col_dir = -1;
    }

    int iter = std::max(std::abs(row_path), std::abs(col_path));

    for(int i = 1; i < iter; i++){
        fromRow += row_dir;
        fromColumn += col_dir;

        if (fromRow < 0 || fromRow >= numRows || fromColumn < 0 || fromColumn >= numCols) {
            return false;  // Path is not clear if it goes out of bounds
        }

        if(getPiece(fromRow, fromColumn) != nullptr){
            return false;
        }
    }


    return true;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn){
    ChessPiece* curr_piece = getPiece(fromRow, fromColumn);

    // Check if there's a piece at the starting position
    if(curr_piece == nullptr){
        return false;
    }

    // Check if the move is to the same position
    if(fromColumn == toColumn && fromRow == toRow){
        return false;
    }

    // Check if the move is out of bounds
    if (toRow < 0 || toRow >= numRows || toColumn < 0 || toColumn >= numCols) {
        return false;
    }

    // Check if the move is valid for the specific piece
    if(!curr_piece->canMoveToLocation(toRow, toColumn)){
        return false;
    }

    // Simulate the move and check if the King is under threat after the move
    ChessPiece *curr = board.at(toRow).at(toColumn);
    board.at(toRow).at(toColumn) = board.at(fromRow).at(fromColumn);
    board.at(fromRow).at(fromColumn) = nullptr;
    board.at(toRow).at(toColumn)->setPosition(toRow, toColumn);
    for(int i = 0; i < getNumRows(); i++){
        for(int j = 0; j < getNumCols(); j++){
            if(board.at(i).at(j) && board.at(i).at(j)->getType() == Type::King && board.at(i).at(j)->getColor() == board.at(toRow).at(toColumn)->getColor()){
                if(isPieceUnderThreat(i,j)){
                    board.at(fromRow).at(fromColumn) = board.at(toRow).at(toColumn);
                    board.at(fromRow).at(fromColumn)->setPosition(fromRow, fromColumn);  
                    board.at(toRow).at(toColumn) = curr;
                    return false;
                }
            }
        }
    }
    board.at(fromRow).at(fromColumn) = board.at(toRow).at(toColumn);
    board.at(fromRow).at(fromColumn)->setPosition(fromRow, fromColumn);  
    board.at(toRow).at(toColumn) = curr;

    return true;
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn){
    ChessPiece* curr_piece = getPiece(fromRow, fromColumn);
    if(isValidMove(fromRow, fromColumn, toRow, toColumn)){
        if(curr_piece->getColor() == turn){
            Color curr_color = curr_piece->getColor();
            Type curr_type = curr_piece->getType();
            createChessPiece(curr_color, curr_type, toRow, toColumn);
            delete board.at(fromRow).at(fromColumn);
            board.at(fromRow).at(fromColumn) = nullptr;
            switchTurn();
            return true;
        }
    }
    return false;
}

bool ChessBoard::isPieceUnderThreat(int row, int col) {
    ChessPiece* Piece_Check = getPiece(row, col);

    if (Piece_Check == nullptr) {
        return false;
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            ChessPiece* piece = board.at(i).at(j);

            if (piece == nullptr){
                continue;
            }
            if(piece->getColor() == Piece_Check->getColor())
                continue;

            // Check for opposing King's adjacency
            if (piece->getType() == Type::King && abs(i - row) <= 1 && abs(j - col) <= 1) {
                return true;
            }

            if (piece->canMoveToLocation(row, col)){
                return true;
            }
        }
    }
    return false;
}


std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << i;
    }
    outputString << std::endl
                 << "  ";
    // top border
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++)
    {
        outputString << row << "|";
        for (int column = 0; column < numCols; column++)
        {
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString());
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl
                 << std::endl;

    return outputString;
}


bool ChessBoard::isOpponentPieceAt(int row, int column, Color curr_color){
    ChessPiece* Piece = getPiece(row, column);
    if(Piece && Piece->getColor() != curr_color){
        return true;
    }

    return false;
}