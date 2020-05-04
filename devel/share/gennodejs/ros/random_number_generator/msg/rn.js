// Auto-generated. Do not edit!

// (in-package random_number_generator.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class rn {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.limit = null;
      this.randint = null;
    }
    else {
      if (initObj.hasOwnProperty('limit')) {
        this.limit = initObj.limit
      }
      else {
        this.limit = 0;
      }
      if (initObj.hasOwnProperty('randint')) {
        this.randint = initObj.randint
      }
      else {
        this.randint = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type rn
    // Serialize message field [limit]
    bufferOffset = _serializer.int32(obj.limit, buffer, bufferOffset);
    // Serialize message field [randint]
    bufferOffset = _serializer.int32(obj.randint, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type rn
    let len;
    let data = new rn(null);
    // Deserialize message field [limit]
    data.limit = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [randint]
    data.randint = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'random_number_generator/rn';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ee411822668b6440d55b15e5b8788d4f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 limit
    int32 randint
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new rn(null);
    if (msg.limit !== undefined) {
      resolved.limit = msg.limit;
    }
    else {
      resolved.limit = 0
    }

    if (msg.randint !== undefined) {
      resolved.randint = msg.randint;
    }
    else {
      resolved.randint = 0
    }

    return resolved;
    }
};

module.exports = rn;
