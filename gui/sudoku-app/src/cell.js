import React from 'react';

class Cell extends React.Component{
    changedValue = (event) => {
        let enteredValue = event.target.value;
        if(enteredValue === ""){
            enteredValue = 0;
        }
        if (this.isValid(enteredValue)) {
            this.props.onChange(enteredValue, this.props.rowIndex, this.props.columnIndex);
        }
    }

    isValid = value => {
        let parsedInt = Number.parseInt(value, 10);
        if(!isNaN(parsedInt) && parsedInt >= 0 && parsedInt <= 9){
            return true;
        }
        return false;
    }

    render() {
        let value = this.props.value;
        return (
            <input 
                type="number" 
                min="1" 
                max="9" 
                value={value !== 0 ? value : ""} 
                onChange={this.changedValue} 
            />
        );
    }
}

export default Cell;