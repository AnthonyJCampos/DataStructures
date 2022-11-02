'use strict';

/**  String Methods Practice a Udemy Problem */

const flights =
  '_Delayed_Departure;fao93766109;txl2133758440;11:25+_Arrival;bru0943384722;fao93766109;11:45+_Delayed_Arrival;hel7439299980;fao93766109;12:05+_Departure;fao93766109;lis2323639855;12:30';

/**
 * Make the above string display to the console as formated below
 *
 * 🔴 Delayed Departure from FAO to TXL (11h25)
 *              Arrival from BRU to FAO (11h45)
 *    🔴 Delayed Arrival from HEL to FAO (12h05)
 *            Departure from FAO to LIS (12h30)
 */

formatFlights(flights);

function formatFlights(flightsString) {
  // first break it into manageable parts

  let line = flightsString.split('+');
  for (let text of line) {
    let formated = text.replaceAll('_', ' ');
    let [status, from, to, time] = formated.split(';');
    from = from.slice(0, 3).toUpperCase();
    to = to.slice(0, 3).toUpperCase();
    time = time.replace(':', 'h');
    status = status.startsWith(' Delayed') ? '🔴' + status : status;
    console.log(`${status} from ${from} to ${to} (${time})`);
  }
} // end formatFlights

/**
 * LeetCode String problem 1108 Defanging an IP Adress
 *
 * Given a valid (IPv4) IP address, return a defanged version of that IP address.
 * A defanged IP address replaces every period "." with "[.]".
 */

const input1108One = '1.1.1.1'; // Output: "1[.]1[.]1[.]1"
const input1108Two = '255.100.50.0'; // Output: "255[.]100[.]50[.]0"
