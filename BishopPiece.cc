/*BishopPiece.cc*/
#include "BishopPiece.hh"
#include <cmath>

namespace Student
{
    BishopPiece::BishopPiece(ChessBoard &board, Color color, int row, int column)
        : ChessPiece(board, color, row, column) {}

    Type BishopPiece::getType(){
        return Bishop;
    }

    bool BishopPiece::canMoveToLocation(int toRow, int toColumn){
        int row_moved = toRow - getRow();
        int column_moved = toColumn - getColumn();
        if(abs(row_moved) != abs(column_moved)){
            return false;
        }

        if(!isPathClear(getRow(), getColumn(), toRow, toColumn)) {
            return false;
        }

        if(!check_color(toRow, toColumn, getColor())){
            return false;
        }

        return true;
    }

    const char *BishopPiece::toString(){
        return (getColor() == White) ? "\u2657" : "\u265d";
    }   
}