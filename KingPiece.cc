/*RookPiece.cc*/
#include "KingPiece.hh"
#include <cmath>

namespace Student
{
    KingPiece::KingPiece(ChessBoard &board, Color color, int row, int column)
                    : ChessPiece(board, color, row, column){}

    Type KingPiece::getType(){
        return King;
    }

    bool KingPiece::canMoveToLocation(int toRow, int toColumn){
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

    const char *KingPiece::toString(){
        return (getColor() == White) ? "\u2656" : "\u265C";
    }

}