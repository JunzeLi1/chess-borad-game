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
        if(row_moved == 0 && column_moved != 0){
            return true;
        }
        if(column_moved == 0 && row_moved != 0){
            return true;
        }

        return false;
    }

    const char *RookPiece::toString(){
        return (getColor() == White) ? "\u2656" : "\u265C";
    }

}