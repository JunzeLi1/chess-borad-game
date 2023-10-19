/*PawnPiece.cc*/
#include "PawnPiece.hh"
#include <cmath>

namespace Student
{
    PawnPiece::PawnPiece(ChessBoard &board, Color color, int row, int column)
        : ChessPiece(board, color, row, column) {}

    Type PawnPiece::getType(){
        return Pawn;
    }

    bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {
        int row_moved = toRow - getRow();
        int column_moved = toColumn - getColumn();
        int board_rows = getBoard().getNumRows();

        if(abs(column_moved) == 1){
            if((getColor() == White && row_moved == -1) || (getColor() == Black && row_moved == 1)){
                if(getBoard().isOpponentPieceAt(toRow, toColumn, getColor())){
                    return true;
                }
            }
        }
        if(getColor() == White){
            if (row_moved == -1 && column_moved == 0
                && getBoard().getPiece(toRow, toColumn) == nullptr){
                return true;
            }
            if(column_moved == 0 && (row_moved == -2 || row_moved == -1) && getRow() == board_rows - 2){
                return true;
            }
        }


        if(getColor() == Black){
            if(column_moved == 0 && (row_moved == 2 || row_moved == 1) && getRow() == 1){
                return true;
            }
            if (row_moved == 1 && column_moved == 0
                && getBoard().getPiece(toRow, toColumn) == nullptr){
                return true;
            }
        }

        return false;
    }

    const char *PawnPiece::toString() {
        return (getColor() == White) ? "\u2659" : "\u265F";
    }
}
