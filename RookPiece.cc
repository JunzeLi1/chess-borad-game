/*RookPiece.cc*/
#include "RookPiece.hh"
#include <cmath>

namespace Student
{
    RookPiece::RookPiece(ChessBoard &board, Color color, int row, int column)
                    : ChessPiece(board, color, row, column){}

    Type RookPiece::getType(){
        return Rook;
    }

    bool RookPiece::canMoveToLocation(int toRow, int toColumn){
        int row_moved = toRow - getRow();
        int column_moved = toColumn - getColumn();
        bool isHorizontalMove = (row_moved == 0 && column_moved != 0);
        bool isVerticalMove = (column_moved == 0 && row_moved != 0);
        if(!isHorizontalMove && !isVerticalMove) {
            return false; // The move is neither horizontal nor vertical
        }

        if(!isPathClear(getRow(), getColumn(), toRow, toColumn)) {
            return false;
        }

        if(!check_color(toRow, toColumn, getColor())){
            return false;
        }

        return true;
    }

    const char *RookPiece::toString(){
        return (getColor() == White) ? "\u2656" : "\u265C";
    }

}