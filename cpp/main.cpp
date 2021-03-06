#include "util.hpp"
#include "search.hpp"
#include "tictactoe.hpp"
#include "reversi.hpp"
#include "animalshogi.hpp"
#include "go.hpp"
#include "geister.hpp"
#include "fliptictactoe.hpp"

using namespace std;

// executable

int main(int argc, char *argv[])
{
    srand(0);

    TicTacToe::init();
    for (int i = 0; i < 10; i++) {
        TicTacToe::State state;
        while (!state.terminal()) {
            auto actions = state.legal_actions();
            cerr << state.to_string() << endl;
            cerr << actions << endl;
            cerr << minimax_search(state) << endl;
            cerr << alpha_beta_search(state) << endl;
            state.play(actions[rand() % actions.size()]);
        }
        cerr << state.to_string() << endl;
        cerr << "reward = " << state.reward(false) << endl;
    }

    Reversi::init();
    for (int i = 0; i < 10; i++) {
        Reversi::State state;
        while (!state.terminal()) {
            auto actions = state.legal_actions();
            cerr << state.to_string() << endl;
            cerr << actions << endl;
            state.play(actions[rand() % actions.size()]);
        }
        cerr << state.to_string() << endl;
        cerr << "reward = " << state.reward(false) << endl;
    }

    AnimalShogi::init();
    for (int i = 0; i < 10; i++) {
        AnimalShogi::State state;
        while (!state.terminal()) {
            auto actions = state.legal_actions();
            cerr << state.to_string() << endl;
            cerr << actions << endl;
            state.play(actions[rand() % actions.size()]);
        }
        cerr << state.to_string() << endl;
        cerr << "reward = " << state.reward(false) << endl;
    }

    Go::init();
    for (int i = 0; i < 10; i++) {
        Go::State state;
        while (!state.terminal()) {
            auto actions = state.legal_actions();
            cerr << state.to_string() << endl;
            cerr << actions << endl;
            state.play(actions[rand() % actions.size()]);
        }
        cerr << state.to_string() << endl;
        cerr << "reward = " << state.reward(false) << endl;
    }

    Geister::init();
    for (int i = 0; i < 10; i++) {
        Geister::State state;
        while (!state.terminal()) {
            auto actions = state.legal_actions();
            cerr << state.to_string() << endl;
            cerr << actions << endl;
            state.play(actions[rand() % actions.size()]);
        }
        cerr << state.to_string() << endl;
        cerr << "reward = " << state.reward(false) << endl;
    }

    FlipTicTacToe::init();
    for (int i = 0; i < 10; i++) {
        FlipTicTacToe::State state;
        while (!state.terminal()) {
            cerr << state.to_string() << endl;
            state.chance();
            if (state.terminal()) break;
            auto actions = state.legal_actions();
            cerr << state.to_string() << endl;
            cerr << actions << endl;
            state.play(actions[rand() % actions.size()]);
        }
        cerr << state.to_string() << endl;
        cerr << "reward = " << state.reward(false) << endl;
    }
}
