/*KingPiece.hh*/
#ifndef __KINGPIECE_H__
#define __KINGPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a King chess piece.
 * The class is defined within the Student namespace.
 */

class ChessPiece;
class ChessBoard;

namespace Student
{
    class KingPiece : public ChessPiece
    {
        public:
            KingPiece(ChessBoard &board, Color color, int row, int column) 
                : ChessPiece(board, color, row, column) {}

    };
}

#endif

