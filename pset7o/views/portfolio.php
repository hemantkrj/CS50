<div>
    Your cash balance: $<?= $cash ?>
    <br>
    <br>
</div>
<div>
	<table class = "table table-condensed">
		<thead>
		<tr>
			<th class="text-center">Name</th>
			<th class="text-center">Symbol</th>
			<th class="text-center">Shares</th>
			<th class="text-center">Price</th>
		</tr>
		</thead>
		<tbody>
		<?php foreach ($stocks as $stock): ?>
			<tr>
				<td><?= $stock["name"] ?></td>
				<td><?= $stock["symbol"] ?></td>
				<td><?= $stock["shares"] ?></td> 
				<td><?= $stock["price"] ?></td> 
			</tr>
		<?php endforeach ?>
		</tbody>
	</table>
</div>



