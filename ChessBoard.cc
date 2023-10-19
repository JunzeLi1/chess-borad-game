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
        if(getPiece(fromRow, fromColumn) != nullptr){
            return false;
        }
    }

    return true;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn){
    ChessPiece* curr_piece = getPiece(fromRow, fromColumn);

    if(getPiece(fromRow, fromColumn) == nullptr){
        return false;
    }

    // if(curr_piece->getColor() != turn){
    //     return false;
    // }

    if(fromColumn == toColumn && fromRow == toRow){
        return false;
    }

    if (toRow < 0 || toRow >= numRows || toColumn < 0 || toColumn >= numCols) {
        return false;
    }

    if(!isPathClear(fromRow, fromColumn, toRow, toColumn)){
        return false;
    }

    ChessPiece* dest_piece = getPiece(toRow, toColumn);
    if(dest_piece && dest_piece->getColor() == curr_piece->getColor()){
        return false;
    }

    return curr_piece->canMoveToLocation(toRow, toColumn);
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn){
    return true;
}

bool ChessBoard::isPieceUnderThreat(int row, int column){
    return true;
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
