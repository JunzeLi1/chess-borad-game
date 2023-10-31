/*ChessPiece.cc*/
#include "ChessPiece.hh"

namespace Student
{
    ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column)
        : _board(board), _color(color), _row(row), _column(column) {}


    Color ChessPiece::getColor() {
        return _color;
    }

    int ChessPiece::getRow() {
        return _row;
    }

    int ChessPiece::getColumn() {
        return _column;
    }

    ChessBoard& ChessPiece::getBoard() const {
        return _board;
    }

    void ChessPiece::setPosition(int row, int column) {
        _row = row;
        _column = column;
    }

    Type ChessPiece::getType() {
        return _type;
    }

    bool ChessPiece::isPathClear(int fromRow, int fromColumn, int toRow, int toColumn){
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

            if (fromRow < 0 || fromRow >= _board.getNumRows() || fromColumn < 0 || fromColumn >= _board.getNumCols()) {
                return false;  // Path is not clear if it goes out of bounds
            }

            if(_board.getPiece(fromRow, fromColumn) != nullptr){
                return false;
            }
        }

        return true;
        
    }

    bool ChessPiece::check_color(int toRow, int toColumn, Color curr_color){
        ChessPiece* dest_piece = _board.getPiece(toRow, toColumn);
        if(dest_piece && dest_piece->getColor() == curr_color) {
            return false;
        }
        return true;
    }
}
