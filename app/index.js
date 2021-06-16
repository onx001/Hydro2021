import { writeStringToSerialPort } from "./DataApi.js";

writeStringToSerialPort("HEllo",() => console.log("write success"))