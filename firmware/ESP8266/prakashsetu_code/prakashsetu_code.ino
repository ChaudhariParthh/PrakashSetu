<?php
session_start();
include "db.php";

/* If admin already logged in, go directly to dashboard */
if (isset($_SESSION['admin'])) {
    header("Location: dashboard.php");
    exit;
}

$error = "";

if (isset($_POST['login'])) {
    $u = $_POST['username'];
    $p = $_POST['password'];

    $q = $conn->query(
        "SELECT * FROM users WHERE username='$u' AND password='$p'"
    );

    if ($q->num_rows == 1) {
        $_SESSION['admin'] = $u;
        header("Location: dashboard.php");
        exit;
    } else {
        $error = "Invalid admin credentials";
    }
}
?>
<!DOCTYPE html>
<html>
<head>
<title>Admin Login</title>

<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">

<style>
body{
    min-height:100vh;
    background:#020617;
    display:flex;
    justify-content:center;
    align-items:center;
    color:#fff;
    font-family:'Segoe UI',sans-serif;
}

.card{
    background:#111827;
    padding:30px;
    border-radius:20px;
    width:380px;
    box-shadow:0 0 20px rgba(0,0,0,.4);
}

.modal-content{
    background:#111827;
    color:white;
    border-radius:15px;
}

.modal-header{
    background:#dc3545;
    color:white;
}

.modal-body{
    text-align:center;
}

.modal-body h3{
    color:#ff4d4d;
    font-weight:bold;
}
</style>

</head>

<body>

<div class="card text-center">

    <h3>🔐 Admin Login</h3>

    <?php if ($error): ?>
        <div class="alert alert-danger"><?= $error ?></div>
    <?php endif; ?>

    <form method="post">

        <input
            name="username"
            class="form-control mb-3"
            placeholder="Username"
            required>

        <input
            name="password"
            type="password"
            class="form-control mb-3"
            placeholder="Password"
            required>

        <button
            name="login"
            class="btn btn-danger w-100">
            Login
        </button>

    </form>

    <a href="index.php" class="btn btn-secondary mt-3">
        Back
    </a>

</div>


<!-- Fault Popup -->

<div class="modal fade" id="faultModal" tabindex="-1">

<div class="modal-dialog modal-dialog-centered">

<div class="modal-content">

<div class="modal-header">

<h5 class="modal-title">
🚨 Fault Detection Alert
</h5>

</div>

<div class="modal-body">

<h3>⚠️ STREET LIGHT FAULT DETECTED</h3>

<p class="mt-3">
Please login immediately to inspect the fault.
</p>

</div>

<div class="modal-footer">

<button
class="btn btn-danger"
data-bs-dismiss="modal">
Login Now
</button>

</div>

</div>

</div>

</div>


<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>

<script>

window.onload=function(){

var fault=new bootstrap.Modal(document.getElementById('faultModal'));

fault.show();

};

</script>

</body>
</html>