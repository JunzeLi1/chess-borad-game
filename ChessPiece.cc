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
}
