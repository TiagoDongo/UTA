document.addEventListener("DOMContentLoaded", (event) => {
    const elem_con_btn = document.getElementById("btnConnectId"),
        elem_send_btn = document.getElementById("btnSendId");

    let socket;
//   
    function connect() {
        const username = document.getElementById("username").value;

        socket = new WebSocket("ws://172.16.20.100:8000/ws");

        socket.onopen = () => {
            socket.send(username);

            document.getElementById("msg").disabled = false;
            elem_send_btn.disabled = false;
        };

        socket.onmessage = (event) => {
            const li = document.createElement("li");
            li.textContent = event.data;
            document.getElementById("chat").appendChild(li);
        };
    }
    
    function sendMessage() {
        const input = document.getElementById("msg");
        socket.send(input.value);
        input.value = "";
    }

    elem_con_btn.addEventListener("click", () => {
        connect();
    });
    elem_send_btn.addEventListener("click", () => {
        sendMessage();
    });
    
})