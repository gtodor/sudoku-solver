import React from 'react';
import './App.css';
import Sudoku from './sudoku';
import Header from './header';
import Footer from './footer';

function App() {
  return (
    <div className="App">
      <Header />
      <Sudoku />
      <Footer />
    </div>
  );
}

export default App;
