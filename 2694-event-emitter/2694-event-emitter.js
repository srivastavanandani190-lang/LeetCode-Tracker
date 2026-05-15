class EventEmitter {
    
    constructor() {
        this.events = {};
    }

    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        
        // Create array for event if it doesn't exist
        if (!this.events[eventName]) {
            this.events[eventName] = [];
        }

        // Add callback
        this.events[eventName].push(callback);

        return {
            unsubscribe: () => {
                this.events[eventName] = this.events[eventName]
                    .filter(cb => cb !== callback);
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        
        // No subscribers
        if (!this.events[eventName]) {
            return [];
        }

        // Call all callbacks in order
        return this.events[eventName].map(cb => cb(...args));
    }
}

/**
 * Example Usage
 */
const emitter = new EventEmitter();

function cb1() { return 5; }
function cb2() { return 6; }

emitter.emit("firstEvent"); // []

const sub1 = emitter.subscribe("firstEvent", cb1);
const sub2 = emitter.subscribe("firstEvent", cb2);

console.log(emitter.emit("firstEvent")); // [5, 6]

sub1.unsubscribe();

console.log(emitter.emit("firstEvent")); // [6]