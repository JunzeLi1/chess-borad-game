/*KingPiece.cc*/
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

        if (row_moved > 1 || row_moved < -1 || column_moved > 1 || column_moved < -1) {
            return false;
        }

        if(getBoard().getPiece(toRow, toColumn)&& getBoard().getPiece(toRow, toColumn)->getColor() == getColor()){
            return false;
        }

        return true;
    }


    const char *KingPiece::toString(){
        return (getColor() == White) ? "\u2654" : "\u265A";  // Corrected the Unicode for King
    }

}