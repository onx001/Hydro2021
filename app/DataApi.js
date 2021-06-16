// const SerialPort = require("serialport");
import SerialPort from 'serialport'
import Readline from '@serialport/parser-readline'
import Ready from '@serialport/parser-ready'

export const writeStringToSerialPort = (text,callback) => {
    const port = new SerialPort("COM3", { //open up a port to kit
        baudRate: 115200,
        // autoOpen:false
    });
        
    const readlineParser = port.pipe(new Readline());

    const readyParser = port.pipe(new Ready({delimiter:'READY'}))

    readyParser.on('ready', () => { //run this function after ready byte is received
        console.log('the ready byte sequence has been received. Arduino is ready.')
        port.write(text)
        port.drain(() => {
            callback()
            port.close()//close the port once all done
        })
        // port.close()
    })
}
